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
	cout << fixed << setprecision(8);

	int n; cin >> n;
	vi order(n);
	for (auto &x : order) cin >> x;
	order.insert(begin(order), -1);
	int m; cin >> m;
	double inc = (2*M_PI) / m;
	map<int, vector<pair<double, double>>> typeToLocs;
	typeToLocs[-1].emplace_back(0, 0);

	int mxSize = 0;
	double theta = 0;
	for (int i = 0; i < m; i++) {
		int type; cin >> type;
		typeToLocs[type].emplace_back(cos(theta), sin(theta));
		mxSize = max((int)typeToLocs[type].size(), mxSize);
		theta += inc;
	}

	vector<vector<double>> dp(n+5, vector<double>(mxSize+5, -1));
	auto go = [&](int idx, int subIdx, auto &&go) -> double {
		if (idx >= sz(order) - 1) return 0;

		auto &ans = dp[idx][subIdx];
		if (ans != -1) return ans;

		double curX = typeToLocs[order[idx]][subIdx].first;
		double curY = typeToLocs[order[idx]][subIdx].second;

		double bestChoice = DBL_MAX;
		for (int i = 0; i < (int)typeToLocs[order[idx+1]].size(); i++) {
			auto p = typeToLocs[order[idx+1]][i];
			double nextX = p.first;
			double nextY = p.second;
			double dx = abs(curX - nextX);
			double dy = abs(curY - nextY);
			double dist = sqrt(dx*dx + dy*dy);
			bestChoice = min(bestChoice, go(idx + 1, i, go) + dist);
		}

		return ans = bestChoice;
	};

	cout << go(0, 0, go) << endl;

    return 0;
}

