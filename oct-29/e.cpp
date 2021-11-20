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

	ll r;
	cin >> r;
	ll rs = r * r;

	ll ans = 0;
	for (ll x = 0; x <= r; x++)
		for (ll y = 0; y <= r; y++) {
			ll q = rs - x*x - y*y;
			if (q < 0) continue;
			ll z = sqrt(q);
			if (z * z == q) {
				int count = 0;
				if(x != 0)count++;
				if(y != 0)count++;
				if(z != 0)count++;
				ans += (1 << count);
			}
		}

	cout << ans << endl;

	return 0;
}

