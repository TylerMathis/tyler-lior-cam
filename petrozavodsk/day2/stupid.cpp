#include <bits/stdc++.h>
using namespace std;

bool after(int i, tuple<int, int, int> j) {
	auto [s, e, w] = j;
	return e > i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> intervals(n);
	for (auto & [s, e, w] : intervals)
		cin >> s >> e >> w;

	sort(begin(intervals), end(intervals));

	vector<int> comp;
	comp.reserve(n + n);
	for (auto & [s, e, _] : intervals) {
		comp.push_back(s);
		comp.push_back(e);
	}

	sort(begin(comp), end(comp));
	auto it = unique(begin(comp), end(comp));
	comp.resize(distance(begin(comp), it));

	intervals.insert(begin(intervals), {0, 0, 0});

	vector<long long> dp(n + 1, LLONG_MAX);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		long long remSum = 0;
		priority_queue<long long, vector<long long>, greater<long long>> taken;
		for (int j = 1; j < i; j++) {
			auto [s, e, w] = intervals[j];


			taken.push(w);
			while ((int) size(taken) > k) {
				remSum += taken.top();
				taken.pop();
			}

			cout << remSum << endl;
			dp[i] = min(dp[i], dp[j] + remSum);
		}
	}

	cout << dp[n - 1] << '\n';

	return 0;
}
