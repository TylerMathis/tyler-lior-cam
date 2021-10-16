#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<int> r(n);
	for (auto &x : r) cin >> x;

	vector<int> dp(n, -1);
	auto go = [&](int curLoc, auto &&go) {
		if (curLoc >= n) return 0;
		auto &ans = dp[curLoc];

		if (ans != -1) return ans;

		int takeAll = r[curLoc] + go(curLoc + k+1, go);
		int takeHalf = (r[curLoc] / 2) + go(curLoc + (k / 2)+1, go);
		int takeNone = go(curLoc + 1, go);

		return ans = max(max(takeAll, takeHalf), takeNone);
	};

	// for (int i = 1; i <= n; i++) {
	// 	dp[i] = r[i];
	// 	dp[i] = max(dp[i],dp[i-1]);
	// 	if (i >= k/2) {
	// 		dp[i] = max(dp[i], dp[i - k/2 - 1] + r[i]/2);
	// 		if (i >= k)
	// 			dp[i] = max(dp[i], dp[i - k - 1] + r[i]);
	// 	}
	// }

	// for (int i = 1; i <= n; i++)
	// 	cout << dp[i] << ' ';
	// cout << '\n';

	cout << go(0, go) << endl;

	return 0;
}
