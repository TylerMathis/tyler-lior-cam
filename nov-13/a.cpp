#include <bits/stdc++.h>
using namespace std;

struct lca {
	int Log;
	vector<vector<int>> memo;
	vector<int> depth;

	lca(const vector<vector<int>> & graph, int root) : Log(1), depth(graph.size()) {
		int n = graph.size();
		while ((1 << Log) < n)
			Log++;
		memo.resize(n, vector<int>(Log));
		dfs(root, root, graph);
	}

	void dfs(int node, int par, const vector<vector<int>> & graph) {
		memo[node][0] = par;
		for (int i = 1; i < Log; i++)
			memo[node][i] = memo[memo[node][i - 1]][i - 1];
		for (const auto & to : graph[node]) {
			if (to != par) {
				depth[to] = 1 + depth[node];
				dfs(to, node, graph);
			}
		}
	}

	int kthPar(int node, int k) {
		for (int bit = 0; bit < Log; bit++)
			if (k & (1 << bit))
				node = memo[node][bit];
		return node;
	}

	int getLca(int x, int y) {
		if (depth[x] < depth[y])
			swap(x, y);

		x = kthPar(x, depth[x] - depth[y]);

		if (x == y)
			return x;

		for (int bit = Log - 1; bit >= 0; bit--) {
			if (memo[x][bit] != memo[y][bit]) {
				x = memo[x][bit];
				y = memo[y][bit];
			}
		}

		return memo[x][0];
	}

	int dist(int x, int y) {
		return depth[x] + depth[y] - 2 * depth[getLca(x, y)];
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w;
	cin >> h >> w;

	vector<string> grid(h + 1);
	for (auto & x : grid) {
		if (cin.peek() == '\n')
			cin.ignore();
		getline(cin, x);
	}

	vector<vector<int>> tree(h * w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < 2 * w + 1; j += 2) {

			auto addEdge = [&](int v, int u) {
				tree[v].push_back(u);
			};

			int di = i - 1;
			int dj = j / 2;
			int v = di * w + dj;

			// up
			if (di - 1 >= 0 && di - 1 < h && grid[i - 1][j] == ' ') {
				int u = (di - 1) * w + dj;
				addEdge(v, u);
			}
			// down
			if (grid[i][j] == ' ') {
				int u = (di + 1) * w + dj;
				addEdge(v, u);
			}
			// left
			if (dj - 1 >= 0 && dj - 1 < w && grid[i][j - 1] == ' ') {
				int u = di * w + dj - 1;
				addEdge(v, u);
			}
			// right
			if (dj + 1 >= 0 && dj + 1 < w && grid[i][j + 1] == ' ') {
				int u = di * w + dj + 1;
				addEdge(v, u);
			}
		}
	}

	lca LCA(tree, 0);

	int m;
	cin >> m;
	long long int tot = 0;
	int sx, sy;
	cin >> sx >> sy;
	m--;
	sx--, sy--;
	int v = sx * w + sy;
	while (m--) {
		int ex, ey;
		cin >> ex >> ey;
		ex--, ey--;

		int u = ex * w + ey;
		tot += LCA.dist(v, u);

		v = u;
	}

	cout << tot << endl;

	return 0;
}
