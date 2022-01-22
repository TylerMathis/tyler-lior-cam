#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		auto getMin = [&]() {
			return min(a, min(b, c));
		};

		int best = 0;

		int curr = getMin();
		for (int i = curr; i < curr + 100; i++) {
			int ma = a, mb = b, mc = c;

			int diff = 0;
			if (ma < i) {
				diff += i - ma;
				ma = i;
			}
			if (mb < i) {
				diff += i - mb;
				mb = i;
			}
			if (mc < i) {
				diff += i - mc;
				mc = i;
			}

			int t = d - diff;
			if (t < 0)
				break;

			int mx = max(ma, max(mb, mc));
			if (ma == mx)
				ma += t;
			else if (mb == mx)
				mb += t;
			else
				mc += t;

			best = max(best, ma * ma + mb * mb + mc * mc + 7 * i);
		}

		cout << best << '\n';
	}

	return 0;
}
