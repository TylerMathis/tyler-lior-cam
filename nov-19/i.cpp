#include <bits/stdc++.h>
using namespace std;

istream & operator >> (istream & is, pair<int, int> & p) {
	is >> p.first >> p.second;
	return is;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto & s : grid)
		cin >> s;

	pair<int, int> au, av, bu, bv;
	cin >> au >> av >> bu >> bv;

	auto reset = [&](auto p) {
		auto [i, j] = p;
		grid[i][j] = '.';
	};

	reset(au), reset(av), reset(bu), reset(bv);

	auto bfs = [&](pair<int, int> s) -> pair<vector<vector<int>>, vector<vector<bool>>> {
		queue<pair<int, int>> q;
		vector<vector<bool>> visited(n, vector<bool>(m));

		q.emplace(s.first, s.second);
		visited[s.first][s.second] = 1;

		vector<vector<int>> dist(n, vector<int>(m));

		while (!q.empty()) {
			auto [i, j] = q.front();
			q.pop();

			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					if (abs(k) ^ abs(l)) {
						if (i + k >= 0 && i + k < n && j + l >= 0 &&
								j + l < m) {
							if (grid[i + k][j + l] == '.' &&
									!visited[i + k][j + l]) {
								q.emplace(i + k, j + l);
								visited[i + k][j + l] = 1;
								dist[i + k][j + l] = dist[i][j] + 1;
							}
						}
					}
				}
			}
		}

		return {dist, visited};
	};

	auto [da1, va1] = bfs(au);
	auto [da2, va2] = bfs(av);
	auto [db1, vb1] = bfs(bu);
	auto [db2, vb2] = bfs(bv);

	int minSumDist = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (va1[i][j] && va2[i][j] && vb1[i][j] && vb2[i][j]) {
				minSumDist = min(minSumDist, da1[i][j] + da2[i][j] + db1[i][j] + db2[i][j]);
			}
		}
	}

	if (minSumDist == INT_MAX)
		cout << "IMPOSSIBLE\n";
	else
		cout << minSumDist << '\n';

	return 0;
}
