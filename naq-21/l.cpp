#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> adjList(N);

    int deg[N];
    for (int i = 0 ; i < N; i++)
        deg[i] = 0;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        deg[a]++;
        deg[b]++;
        adjList[a].emplace_back(b, i);
        adjList[b].emplace_back(a, i);
    }

    // Precomp chooses
    ull chooseThree[N+1], chooseTwo[N+1];
    for (int i = 3; i <= N; i++)
        chooseThree[i] = (i * (i - 1) * (i - 2)) / 6;
    for (int i = 2; i <= N; i++)
        chooseTwo[i] = (i * (i - 1)) / 2;

    vi order(N), triCycles(M, 0), markedEdges(N, -1);
    iota(all(order), 0);
    sort(all(order), [ &deg ] (const int &a, const int &b) { return deg[a] < deg[b]; });
    map<int, int> indexOfOrder; for (int i = 0; i < N; i++) indexOfOrder[order[i]] = i;
    for (int v = 0; v < N; v++) {
        for (auto [c, i] : adjList[v]) markedEdges[c] = i;
        for (auto [c, e1] : adjList[v]) {
            if (indexOfOrder[c] >= indexOfOrder[v]) continue;
            for (auto [u, e2] : adjList[c]) {
                if (indexOfOrder[u] >= indexOfOrder[c] || markedEdges[u] == -1) continue;
                triCycles[e1]++; triCycles[e2]++; triCycles[markedEdges[u]]++;
            }
        }
        for (auto [c, i] : adjList[v]) markedEdges[c] = -1;
    }

    ull ans = 0;
    for (int v = 0; v < N; v++) {
        if (deg[v] < 4) continue;
        ull cthree = chooseThree[deg[v] - 1];
        ull ctwo = chooseTwo[deg[v] - 2];
        for (auto [c, i] : adjList[v])
            ans += cthree * (deg[c] - 1) - ctwo * triCycles[i];
    }

    cout << ans << "\n";

    return 0;
}
