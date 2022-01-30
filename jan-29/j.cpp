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
    for (auto &v : grid) for (auto &x : v) cin >> x;
    int card = 0, inter = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (!grid[i][j]) continue;
            inter += grid[i][j+1];
            inter += grid[i+1][j+1];
            inter += grid[i+1][j];
            inter += grid[i+1][j-1];
            card += grid[i][j+1];
            card += grid[i+1][j];
        }
    }

    for (int i = 0; i < m - 1; i++)
        if (grid[n-1][i] && grid[n-1][i+1])
            card++, inter++;
    for (int i = 0; i < n - 1; i++) {
        if (grid[i][m-1] && grid[i+1][m-1])
            card++, inter++;
        if (grid[i][m-1] && grid[i+1][m-2])
            inter++;
    }

    cout << card << ' ' << inter << endl;

    return 0;
}

