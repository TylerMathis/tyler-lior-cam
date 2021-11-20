#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> indeg(n);
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        s--, t--;
        indeg[t]++;
        adj[s].emplace_back(t, c);
    }

    queue<int> q;
    for (int v = 0; v < n; v++)
        if (!indeg[v])
            q.push(v);

    vector<int> len(n);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto [u, w] : adj[v]) {
            len[u] = max(len[u], len[v] + w);
            if (!--indeg[u])
                q.push(u);
        }
    }

    int mx = 0;
    for (int v = 0; v < n; v++)
        mx = max(mx, len[v]);

    cout << mx << endl;

    return 0;
}
