#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<tuple<int, int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		edges[i] = {w, a, b};
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}

	sort(begin(edges), end(edges));

	int q;
	cin >> q;
	vector<pair<int, int>> thresh(q);
	for (int i = 0; i < q; i++) {
		cin >> thresh[i].first;
		thresh[i].second = i;
	}

	int nodeCnt = n;
	int edgeCnt = m;
	auto compress = [&](int i){
		if (adj[i].empty())
			nodeCnt--;
		if (adj[i].size() == 2 && adj[i][0].first != adj[i][1].first) {
			nodeCnt--;
			edgeCnt--;
			adj[adj[i][0].first].emplace_back(adj[i][1].first, INT_MAX);
			adj[adj[i][1].first].emplace_back(adj[i][0].first, INT_MAX);
			adj[i].clear();
		}
	};

	for (int i = 0; i < n; i++)
		compress(i);

	sort(begin(thresh), end(thresh));

	int idx = 0;
	vector<pair<int, int>> res(q);
	for (const auto & [th, i] : thresh) {
		vector<int> ind;
		while (idx < m && get<0>(edges[idx]) < th) {
			auto [w, a, b]= edges[idx];
			ind.push_back(a);
			ind.push_back(b);
			idx++;
		}

		sort(begin(ind), end(ind));

		for (const int & b : ind)
			compress(b);

		res[i] = {nodeCnt, edgeCnt};
	}

	for (const auto &[x, y] : res)
		cout << x << ' ' << y << endl;

	return 0;
}
