#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;

    vector<vi> grid(n, vi(m));
    for (auto &r : grid)
        for (auto &v : r)
            cin >> v;

    int DR[] = {1, 0, -1, 0}, DC[] = {0, 1, 0, -1};
    auto dfs = [&](int row, int col, int type, bool flag, vector<pii> &locs1, vector<pii> &locs2, auto &&dfs) -> void {
        grid[row][col] = -1;
        if (flag) locs1.emplace_back(row, col);
        else locs2.emplace_back(row, col);

        for (int d = 0; d < 4; d++) {
            int nr = row + DR[d];
            int nc = col + DC[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (grid[nr][nc] != type)
                continue;

            dfs(nr, nc, type, !flag, locs1, locs2, dfs);
        }
    };

    // Find all components and double bfs
    vector<pii> ans;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == -1) continue;
            vector<pii> locs1, locs2;
            dfs(r, c, grid[r][c], true, locs1, locs2, dfs);

            if (sz(locs1) < sz(locs2))
                ans.insert(end(ans), begin(locs1), end(locs1));
            else ans.insert(end(ans), begin(locs2), end(locs2));
        }
    }

    cout << (sz(ans) == 0 ? 0 : 1) << ' ' << sz(ans) << "\n";
    for (auto &[r, c] : ans)
        cout << r+1 << ' ' << c+1 << ' ' << 1 << "\n";

    return 0;
}

