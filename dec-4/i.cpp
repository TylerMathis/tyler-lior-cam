#include <bits/stdc++.h>
using namespace std;

struct Item {
	int d, s, i;
};

struct State {
	int w = 0;
	bool taken = 0;
};

template<typename Os, typename T> Os & operator << (Os & os, const vector<T> & v) {
	for (const auto & x : v)
		os << x << ' ';
	return os;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, c;
	cin >> n >> c;
	vector<Item> items(n);
	for (int i = 1; i <= n; i++) {
		cin >> items[i - 1].d >> items[i - 1].s;
		items[i - 1].i = i;
	}

	sort(begin(items), end(items), [](const auto & a, const auto & b)
			{ return tie(a.s, a.d) < tie(b.s, b.d); });

	auto itemss = items;

	auto knapsack = [&](const auto & items) {
		vector<vector<State>> dp(n + 1, vector<State>(c + 1));

		for (int i = 1; i <= n; i++) {
			auto item = items[i - 1];

			for (int j = 0; j <= c; j++) {
				int left = item.s + c - j;

				if (j >= item.s && left >= item.d) {
					dp[i][j].w = 1 + dp[i - 1][j - item.s].w;
					dp[i][j].taken = 1;
				}
				else {
					dp[i][j].w = dp[i - 1][j].w;
				}
			}
		}

		return dp;
	};

	auto dps = knapsack(itemss);

	sort(begin(items), end(items), [](const auto & a, const auto & b)
			{ return tie(a.d, a.s) > tie(b.d, b.s); });

	auto itemsd = items;

	auto dpd = knapsack(itemsd);

	auto buildBack = [&](const auto & dp, const auto & items) {
		int total = dp[n][c].w;
		int i = n;
		int j = c;
		int cnt = 0;

		vector<int> order;
		order.reserve(total);
		while (cnt < total) {
			if (dp[i][j].taken) {
				order.push_back(items[i - 1].i);
				j -= items[i - 1].s;
				cnt++;
			}
			i--;
		}

		reverse(begin(order), end(order));
		return order;
	};

	if (dps[n][c].w > dpd[n][c].w)
		cout << dps[n][c].w << '\n' << buildBack(dps, itemss) << '\n';
	else
		cout << dpd[n][c].w << '\n' << buildBack(dpd, itemsd) << '\n';

	return 0;
}
