#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> & dag, int u, vector<bool> & seen, vector<int> & order) {
    seen[u] = 1;
    for (auto v : dag[u]) {
	if (!seen[v]) {
	    dfs(dag, v, seen, order);
	}
    }
    order.push_back(u);
}

vector<int> topological_sort(const vector<vector<int>> & dag) {
    int n = size(dag);
    vector<int> order;
    vector<bool> seen(n);
    for (int u = 0; u < n; u++) {
	if (!seen[u]) {
	    dfs(dag, u, seen, order);
	}
    }
    return order;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    bool color = 1;
    if (k < n - k) {
	k = n - k;
	color = 0;
    }
    vector<int> t(n);
    for (auto & x : t)
	cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
	int u, v;
	cin >> u >> v, u--, v--;
	g[u].push_back(v);
	g[v].push_back(u);
    }

    vector<vector<int>> dag(n);
    vector<int> d(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(t[n - 1], n - 1);
    d[n - 1] = t[n - 1];
    while (!pq.empty()) {
	auto [du, u] = pq.top();
	pq.pop();

	if (du > d[u])
	    continue;

	for (auto v : g[u]) {
	    if (d[u] + t[v] < d[v]) {
		d[v] = d[u] + t[v];
		pq.emplace(d[v], v);
		dag[v] = {u};
	    } else if (d[u] + t[v] == d[v]) {
		dag[v].push_back(u);
	    }
	}
    }

    auto order = topological_sort(dag);

    unordered_set<int> has;
    has.reserve(n);
    for (auto x : order)
	has.insert(x);

    for (int i = 0; i < n && (int) size(has) < k; i++)
	if (has.insert(i).second)
	    order.push_back(i);

    vector<bool> units(n, !color);
    for (int i = 0; i < k; i++)
	units[order[i]] = color;

    queue<int> q;
    vector<bool> seen(n);
    q.push(0);
    seen[0] = 1;
    while (!q.empty()) {
	auto u = q.front();
	q.pop();

	for (auto v : dag[u]) {
	    if ((units[u] ^ units[v]) && !seen[v]) {
		q.push(v);
		seen[v] = 1;
	    }
	}
    }

    if (seen[n - 1]) {
	cout << "impossible\n";
	return 0;
    }

    for (int i = 0; i < n; i++) {
	if (units[i])
	    cout << 'N';
	else
	    cout << 'S';
    }
    cout << '\n';

    return 0;
}
