#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> a;

bool possible(int volume) {
	int rounds = 0;

	for (int i = 0; i < n;) {
		int sum = 0;

		if (a[i] > volume)
			return 0;

		while (i < n && sum + a[i] <= volume) {
			sum += a[i];
			i++;
		}
		rounds++;
	}

	return rounds <= k;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;

	a = vector<int>(n);
	for (auto & x : a)
		cin >> x;

	int ans = 0;
	int mx = 1e6 * 5 * 1e5 + 10;
	int mn = 0;
	while (mn <= mx) {
		int mid = (mx + mn) / 2;
		if (possible(mid)) {
			ans = mid;
			mx = mid - 1;
		}
		else
			mn = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
