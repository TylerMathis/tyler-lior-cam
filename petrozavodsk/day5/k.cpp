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

    int n, m; cin >> n >> m;
    int q; cin >> q;

    vector<vi> mat(n, vi(m));
    for (auto &v : mat)
        for (auto &x : v)
            cin >> x;

    // 0-left 1-up 2-right 3-down
    int DR[4] = {0, -1, 0, 1}, DC[4] = {-1, 0, 1, 0};
    vector<vector<vi>> connects(n, vector<vi>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (abs(mat[nr][nc] - mat[r][c]) > 1) continue;
                connects[r][c].push_back(d);
            }
        }
    }

    vector<vi> numEdges(n+1, vi(m+1));
    vector<vi> colExitLeft(m, vi(n+1)), colExitRight(m, vi(n+1));
    vector<vi> rowExitUp(n, vi(m+1)), rowExitDown(n, vi(m+1));

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            numEdges[r+1][c+1] = numEdges[r][c+1] + numEdges[r+1][c] - numEdges[r][c] + sz(connects[r][c]);
    
    for (int c = 0; c < m; c++)
        for (int r = 0; r < n; r++)
            colExitLeft[c][r+1] = colExitLeft[c][r] + (find(all(connects[r][c]), 0) != end(connects[r][c])),
            colExitRight[c][r+1] = colExitRight[c][r] + (find(all(connects[r][c]), 2) != end(connects[r][c]));
    
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            rowExitUp[r][c+1] = rowExitUp[r][c] + (find(all(connects[r][c]), 1) != end(connects[r][c])),
            rowExitDown[r][c+1] = rowExitDown[r][c] + (find(all(connects[r][c]), 3) != end(connects[r][c]));

    auto queryRange2D = [](vector<vi> &pref2D, int sr, int sc, int er, int ec) {
        return pref2D[er+1][ec+1] - pref2D[sr][ec+1] - pref2D[er+1][sc] + pref2D[sr][sc];
    };

    auto queryRange = [](vi &pref, int l, int r) {
        return pref[r+1] - pref[l];
    };

    for (int i = 0; i < q; i++) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        sr--, sc--, er--, ec--;

        ll cont = queryRange2D(numEdges, sr, sc, er, ec);

        // Exclude exit lefts
        int left = queryRange(colExitLeft[sc], sr, er);
        int right = queryRange(colExitRight[ec], sr, er);
        int up = queryRange(rowExitUp[sr], sc, ec);
        int down = queryRange(rowExitDown[er], sc, ec);
        cont = cont - left - right - up - down;

        ll numNodes = (er - sr + 1) * (ec - sc + 1);

        if (cont >= numNodes*2 - 2 && cont <= numNodes*2) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}