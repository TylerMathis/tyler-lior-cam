#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int c, n;
	cin >> c >> n;
	vector<int> a(n);
	for (auto & x : a)
		cin >> x;

	vector<pair<int, int>> errs;
	errs.emplace_back(a[0], a[0]);
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1] + 1) {
			errs.back().second = a[i];
		} else {
			errs.emplace_back(a[i], a[i]);
		}
	}

	vector<pair<int, int>> crrs;
	if (errs.front().first != 1)
		crrs.emplace_back(1, errs.front().first - 1);

	cout << "Errors: ";

	for (int i = 0; i < (int) size(errs); i++) {
		auto [a, b] = errs[i];

		if (i > 0) {
			if (i == (int) size(errs) - 1) {
				cout << " and ";
			} else {
				cout << ", ";
			}
		}

		if (a == b) {
			cout << a;
		} else {
			cout << a << '-' << b;
		}

		if (i < (int) size(errs) - 1) {
			crrs.emplace_back(b + 1, errs[i + 1].first - 1);
		}
	}

	if (errs.back().second < c) {
		crrs.emplace_back(errs.back().second + 1, c);
	}

	cout << '\n';

	cout << "Correct: ";
	for (int i = 0; i < (int) size(crrs); i++) {
		auto [a, b] = crrs[i];

		if (i > 0) {
			if (i == (int) size(crrs) - 1) {
				cout << " and ";
			} else {
				cout << ", ";
			}
		}

		if (a == b) {
			cout << a;
		} else {
			cout << a << '-' << b;
		}
	}

	cout << '\n';

	return 0;
}

