#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct location {
    int row, col, maxDepth;
    location(int row, int col, int maxDepth) : row(row), col(col), maxDepth(maxDepth) {}
    bool operator<(const location &o) const {
        return maxDepth < o.maxDepth;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int h, w; cin >> h >> w;

    vector<vi> grid(h, vi(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if (grid[i][j] >= 0)
                visited[i][j] = true, grid[i][j] = INT_MIN;
            else grid[i][j] *= -1;
        }

    int dRow, dCol; cin >> dRow >> dCol;
    dRow--; dCol--;

    priority_queue<location> bfs;
    bfs.emplace(dRow, dCol, grid[dRow][dCol]);
    visited[dRow][dCol] = true;

    while (!bfs.empty()) {
        auto [row, col, maxDepthToMe] = bfs.top();
        bfs.pop();

        for (int nrow = row - 1; nrow <= row + 1; nrow++) {
            for (int ncol = col - 1; ncol <= col + 1; ncol++) {
                if (nrow >= 0 && nrow < h && ncol >= 0 && ncol < w) {
                    if (!visited[nrow][ncol]) {
                        int newDepth = min(maxDepthToMe, grid[nrow][ncol]);
                        bfs.emplace(nrow, ncol, newDepth);
                        grid[nrow][ncol] = newDepth;
                        visited[nrow][ncol] = true;
                    }
                }
            }
        }
    }

    ll totalFlow = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            if (grid[i][j] != INT_MIN && visited[i][j])
                totalFlow += grid[i][j];
        }
        
    cout << totalFlow << endl;  

    return 0;
}