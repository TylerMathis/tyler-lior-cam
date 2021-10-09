#include <bits/stdc++.h>
#define int long long
using namespace std;

struct BipartiteMatcher {
	vector<vector<int>> G;
	vector<int> L, R, Viz;
	vector<bool> visitedA, visitedB;
	BipartiteMatcher(int n, int m) :
		G(n), L(n, -1), R(m, -1), Viz(n), visitedA(n), visitedB(m) { }

	void AddEdge(int a, int b) {
		G[a].push_back(b);
	}

	bool Match(int node) {
		if (Viz[node])
			return false;
		Viz[node] = true;
		for (auto vec : G[node]) {
			if (R[vec] == -1 || Match(R[vec])) {
				L[node] = vec;
				R[vec] = node;
				return true;
			}
		}
		return false;
	}

	int Solve() {
		bool ok = true;
		while (ok) {
			ok = false;
			fill(Viz.begin(), Viz.end(), 0);
			for (int i = 0; i < (int) L.size(); i++)
				if (L[i] == -1)
					ok |= Match(i);
		}

		int ret = 0;
		for (int i = 0; i < (int) L.size(); i++)
			ret += (L[i] != -1);
		return ret;
	}

	void dfs(int node) {
		visitedA[node] = true;
		for (auto to : G[node]) {
			if (!visitedB[to] && R[to] != -1) {
				visitedB[to] = true;
				dfs(R[to]);
			}
		}
	}
};

void solve() {
	int n;
	cin >> n;
	BipartiteMatcher bm(n, 2 * n);

	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		p--, q--;
		bm.AddEdge(i, p);
		bm.AddEdge(i, q);
	}

	if (bm.Solve() >= n)
		cout << "possible\n";
	else
		cout << "impossible\n";
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
