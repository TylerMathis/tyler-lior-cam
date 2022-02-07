#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<vi> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    int root = 0;
    for (int i = 0; i < n; i++) if (sz(adj[i]) == 1) {
        root = i;
        break;
    }

    auto go = [&](int idx, bool parity, int par, auto &&go) -> ll {
        if (par != -1) {
            if (sz(adj[idx]) == 1 && parity == 1) return INT_MAX;
            else if (sz(adj[idx]) == 1) return 0;
        }
        
        auto &ans = dp[idx][parity];
        if (ans != -1) return ans;

        ans = 0;
        for (int u : adj[idx]) {
            if (u == par) continue;
            ans += min(go(u, !parity, idx, go), go(u, parity, idx, go) + 1);
        }

        return ans;
    };

    cout << go(root, 0, -1, go) << endl;
    
    return 0;
}