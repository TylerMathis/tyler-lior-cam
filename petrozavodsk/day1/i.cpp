#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

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

struct SegmentTree {
	struct Node {
		ll mn = LLONG_MAX;
		int l, r;
		ll lazy = 0;
	};

	vector<Node> tree;
	int n;

	Node combineChildren(const Node & L, const Node & R) {
		return Node {
			min(L.mn, R.mn),
				L.l,
				R.r
		};
	}

	void applyDeltaOnRange(int node, ll delta) {
		int start = tree[node].l, end = tree[node].r;
		tree[node].mn += delta;
		if (start != end) {
			tree[2*node].lazy += delta;
			tree[2*node+1].lazy += delta;
		}
	}

	void pushLazy(int node) {
		ll& currLazy = tree[node].lazy;
		if (currLazy) {
			applyDeltaOnRange(node, currLazy);
			currLazy = 0;
		}
	}

	SegmentTree(const vector<ll> & arr) : n((int)arr.size()) {
		auto build = [&](auto && buildPtr, int node, int start, int end) -> void {
			if (start == end) {
				tree[node] = Node {
					arr[start],
					start,
					end
				};
			} else {
				int mid = (start+end) / 2;
				buildPtr(buildPtr, 2*node, start, mid);
				buildPtr(buildPtr, 2*node+1, mid+1, end);
				tree[node] = combineChildren(tree[2*node], tree[2*node+1]);
			}
		};
		int size = 1;
		while (size < n) size <<= 1;
		size <<= 1;
		tree.resize(size);
		build(build, 1, 0, n-1);
	}

	void update(int l, int r, ll diff) {
		auto update = [&](auto&& updatePtr, int node) -> void {
			pushLazy(node);
			int start = tree[node].l, end = tree[node].r;
			if (r < start || end < l) return;
			if (l <= start && end <= r) {
				applyDeltaOnRange(node, diff);
				return;
			}
			updatePtr(updatePtr, 2*node);
			updatePtr(updatePtr, 2*node+1);
			tree[node] = combineChildren(tree[2*node], tree[2*node+1]);
		};
		update(update, 1);
	}

	Node query(int l, int r) {
		auto query = [&](auto && queryPtr, int node) -> Node {
			int start = tree[node].l, end = tree[node].r;
			if (r < start || end < l) return Node();
			pushLazy(node);
			if (l <= start && end <= r) return tree[node];
			return combineChildren(
					queryPtr(queryPtr, 2*node),
					queryPtr(queryPtr, 2*node+1)
					);
		};
		return query(query, 1);
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p, p--;
		if (p != i) {
			g[p].push_back(i);
			g[i].push_back(p);
		}
	}

	vector<ll> a(n), c(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	auto subtreeSum = [&](int u, int p, auto & sums, auto && dfs) -> void {
		for (auto & v : g[u]) {
			if (v != p) {
				dfs(v, u, sums, dfs);
				sums[u] += sums[v];
			}
		}
	};

	vector<ll> aSum = a;
	vector<ll> cSum = c;
	subtreeSum(0, -1, aSum, subtreeSum);
	subtreeSum(0, -1, cSum, subtreeSum);

	hld HLD(g, 0);

	vector<ll> diff(n); // aSum - cSum
	for (int i = 0; i < n; i++) {
		diff[HLD.timeIn[i]] = aSum[HLD.timeIn[i]] - cSum[HLD.timeIn[i]];
	}

	SegmentTree rmq(diff);

	if (rmq.query(0, n - 1).mn < 0) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}

	int q;
	cin >> q;
	while (q--) {
		int t, v, x;
		cin >> t >> v >> x, v--;
		ll diffVal = 0;
        if (t == 1) {
            diffVal = x - a[v];
            a[v] = x;
        } else {
            diffVal = c[v] - x;
            c[v] = x;
        }
		auto path = HLD.path(0, v);
		for (auto [ta, tb] : path) {
			rmq.update(ta, tb, diffVal);
		}

		if (rmq.query(0, n - 1).mn < 0) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}

	return 0;
}
