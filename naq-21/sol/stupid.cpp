#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	pair<int, int> mx = make_pair(0, 0);

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int f = 0;
		for (int j = 2; j <= i; j++)
			if (__gcd(i, j) > 1)
				f++;

		int gcd = __gcd(f, i);

		if (mx == make_pair(0ll, 0ll))
			mx = make_pair(f / gcd, i / gcd);
		else {
			auto [a, b] = mx;
			__int128_t lcm = b * i / __gcd(b, i);
			__int128_t mulA = lcm / b;
			__int128_t mulB = lcm / i;

			if (a * mulA < f * mulB)
				mx = make_pair(f / gcd, i / gcd);
		}
	}

	cout << mx.first << '/' << mx.second << '\n';

	return 0;
}
