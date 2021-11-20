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

	ll num; cin >> num;

	int upper = 1e8;
	vector<ll> powers(upper);
	for (ll i = 0; i < upper; i++)
		powers[i] = i*i;

	for (int pw = 2; pw <= 70; pw++) {
		ll sum = 0;
		int idx = 0;
		while (sum < num && idx < upper) {
			if (powers[idx] < 0) break;
			if ((ll)1e18 - powers[idx] > sum)
				sum += powers[idx++];
			else break;

			if (sum == num) {
				cout << pw+1 << ' ' << idx-1 << endl;
				return 0;
			}
		}

		upper = 1e6;
		for (int i = 0; i < upper; i++)
			if (1e18 / i > powers[i])
				powers[i] *= i;
	}

	cout << "impossible" << endl;

    return 0;
}

