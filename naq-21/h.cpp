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

	int n;
	cin >> n;
	int x;
	cin >> x;
	n--;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % x == 0) {
			cout << a << '\n';
			if (i < n) {
				cin >> x;
				i++;
			}
		}
	}

	return 0;
}
