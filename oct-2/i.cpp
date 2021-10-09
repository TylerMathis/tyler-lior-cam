#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, xl, yl, xb, yb; cin >> n >> xl >> yl >> xb >> yb;
    map<int, vi> xs, ys;
    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        xs[x].push_back(y);
        ys[y].push_back(x);
    }

    // bfs in four directions
    int bestDist = INT_MAX;
    for (int i = 0; i < 4; i++) {
        queue<tuple<int, int, int, int>> bfs;
        map<pii, bool> visited;
        
        bfs.emplace(xl, yl, i, 0);
        visited[{xl, yl}] = true;

        while (!bfs.empty()) {
            auto [x, y, dir, dist] = bfs.front();
            bfs.pop();

            if (x == xb || y == yb) {
                bestDist = min(bestDist, dist);
                break;
            }

            if (dir == 0 || dir == 2) {
                // always turn
                for (int nextY : xs[x]) {
                    pii p = {x, nextY};
                    if (visited[p]) continue;
                    visited[p] = true;

                    if (nextY > y) bfs.emplace(x, nextY, 1, dist + 1);
                    else bfs.emplace(x, nextY, 3, dist + 1);
                }
            }
            if (dir == 1 || dir == 3) {
                // always turn
                for (int nextX : ys[y]) {
                    pii p = {nextX, y};
                    if (visited[p]) continue;
                    visited[p] = true;

                    if (nextX > x) bfs.emplace(nextX, y, 0, dist + 1);
                    else bfs.emplace(nextX, y, 2, dist + 1);
                }
            }
        }
    }

    cout << (bestDist == INT_MAX ? -1 : bestDist) << endl;

    return 0;
}
