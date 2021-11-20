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

	int n; cin >> n;
	vi one(n), two(n);
	for (auto &x : one) cin >> x;
	for (auto &x : two) cin >> x;

	int diff = two[0] - one[0];

	if (diff < 0) {
		cout << 0 << endl;
		return 0;
	}

	// try equal;
	for (int i = 0; i < n; i++)
		one[i] += diff;

	bool good = true;
	for (int i = 0; i < n; i++) {
		if (one[i] < two[i]) {
			good = false;
			break;
		}
	}

	if (good) {
		cout << diff << endl;
		return 0;
	}

	cout << diff+1 << endl;

    return 0;
}

