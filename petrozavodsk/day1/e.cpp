#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// struct UF {
//     vi e;
//     UF(int n) : e(n, -1) {}
//     bool sameSet(int a, int b) { return find(a) == find(b); }
//     int size(int x) { return -e[find(x)]; }
//     int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
//     bool join(int a, int b) {
//         a = find(a), b = find(b);
//         if (a == b) return false;
//         if (e[a] > e[b]) swap(a, b);
//         e[a] += e[b]; e[b] = a;
//         return true;
//     }
// };

vector<int> edgeId;
map<pair<int, int>, int> edgeToIdx;

struct hld {
	vector<int> Size, par, Depth, timeIn, Next, timeInToNode;
	hld(vector<vector<int>>& adj, int root = -1):
		Size(adj.size(),1), par(adj.size(),-1), Depth(adj.size(),1), timeIn(adj.size()), Next(adj.size(), -1), timeInToNode(adj.size()) {
			int Time = 0;
			auto callDfss = [&](int node) -> void {
				Next[node] = par[node] = node;
				dfs1(node, adj);
				dfs2(node, adj, Time);
			};
			if (root != -1) {
				callDfss(root);
			}
			for (int i = 0; i < (int)adj.size(); i++) {
				if (par[i] == -1) {
					callDfss(i);
				}
			}
		}
	void dfs1(int node, vector<vector<int>>& adj) {
		for (auto& to: adj[node]) {
			if (to == par[node]) continue;
			Depth[to] = 1 + Depth[node];
			par[to] = node;
			dfs1(to, adj);
			Size[node] += Size[to];
			if (Size[to] > Size[adj[node][0]] || adj[node][0] == par[node]) {
				swap(to, adj[node][0]);
			}
		}
	}
	void dfs2(int node, const vector<vector<int>>& adj, int& Time) {
		timeIn[node] = Time;
		timeInToNode[Time] = node;
		Time++;
		for (auto to: adj[node]) {
			if (to == par[node]) continue;
			Next[to] = (Time == timeIn[node] + 1 ? Next[node] : to);
			dfs2(to, adj, Time);
		}
	}
	vector<pair<int, int>> path(int u, int v) const {
		vector<pair<int, int>> res;
		for (;; v = par[Next[v]]) {
			if (timeIn[v] < timeIn[u]) swap(u, v);
			if (timeIn[Next[v]] <= timeIn[u]) {
				res.push_back({timeIn[u], timeIn[v]});
				return res;
			}
			res.push_back({timeIn[Next[v]], timeIn[v]});
		}
	}
	pair<int, int> subtree(int i) const {
		return {timeIn[i], timeIn[i] + Size[i] - 1};
	}
	int lca(int u, int v) const {
		for (;; v = par[Next[v]]) {
			if (timeIn[v] < timeIn[u]) swap(u, v);
			if (timeIn[Next[v]] <= timeIn[u]) return u;
		}
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> tree(n);
	vector<tuple<int, int, int>> edges(m);
	edgeId = vector<int>(n);

	for (auto & [a, b, c] : edges) {
		cin >> a >> b >> c, a--, b--;
		if (c == 1) {
			tree[a].push_back(b);
			tree[b].push_back(a);
		} else {
		}
	}

	hld HLD(tree, 0);

	SegmentTree rmq(vector<int>(n)); // rmq on edges (child inhereits the edge value)

	auto pathMin = [&](int a, int b) {
		int idx = 0;
		int mn = 1;
		for (auto & [u, v] : HLD.path(a, b)) {
			auto node = rmq.query(HLD.timeIn[u], HLD.timeIn[v]);
			if (node.mn == 0) {
				return HLD.timeInToNode[node.idx];
			}
		}
		return -1;
	};

	int w = 1;
	vector<int> p(m);
	for (int i = 0; i < m; i++) {
		if (p[i])
			continue;
		auto & [a, b, c] = edges[i];
		if (c == 1) {
			p[i] = w;
			rmq.update(max(HLD.timeIn[a], HLD.timeIn[b]), INT_MAX);
			w++;
			continue;
		}
		while (1) {
			auto idx = pathMin(a, b);
			if (mn)
				break;
			p[idx] = w;
			w++;
			rmq.update(max(HLD.timeIn[a], HLD.timeIn[b]), INT_MAX);
		}
	}

	return 0;
}
