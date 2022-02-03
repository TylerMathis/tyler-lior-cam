#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int colored;

int dfs(int u) {
    if (g[u].size() == 0) return 1;

    int leaves = 0;
    for (auto &v : g[u])
        leaves += dfs(v);

    if (
        leaves > 1 ||
        (u == 0 && colored == 0) ||
        (u == 0 && (int)g[u].size() == 1 && leaves > 0)) {
        colored++;
        leaves = 0;
    }

    return leaves;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    g = vector<vector<int>>(n);
    colored = 0;
    for (int i = 1; i < n; i++) {
        int p; cin >> p, p--;
        g[p].push_back(i);
    }

    dfs(0);
    cout << colored << endl;
    
    return 0;
}
