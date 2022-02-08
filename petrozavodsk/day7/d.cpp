#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
    int n, k; cin >> n >> k;

    if (n == k || n - 2 == k) {
        cout << -1 << "\n";
        return;
    }

    if (n <= 5 && k == 0) {
        cout << n << "\n";
        for (int u = 1; u <= n; u++) {
            if (u == n) cout << u << " " << 1 << "\n";
            else cout << u << " " << u+1 << "\n";
        }
        return;
    }

    if (n == 6 && k == 0) {
        cout << "7\n";
        for (int u = 1; u < n; u++)
            cout << u << " " << u+1 << "\n";
        cout << "3 6\n";
        cout << "1 5\n";
        return;
    }

    int root = k + 1;
    vector<pii> ans;
    for (int node = 1; node <= n; node++) if (node != root)
        ans.emplace_back(node, root);

    for (int node = root + 1; node <= n; node += 2) {
        if (node == n)
            ans.emplace_back(node-1, node);
        else
            ans.emplace_back(node, node+1);
    }

    cout << sz(ans) << "\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve();

    return 0;
}