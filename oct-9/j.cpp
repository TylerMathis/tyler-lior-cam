#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
pair<vector<bool>, vector<T>> dijkstra(
 const vector<vector<pair<int, T>>>& adj, int s) {
    using ST = pair<T, int>;
    priority_queue<ST, vector<ST>, greater<ST>> q;
    vector<T> dist(adj.size());
    vector<bool> seen(adj.size());
    q.emplace(T{}, s);
    seen[s] = 1;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u])
            if (!seen[v] || d + w < dist[v]) {
                q.emplace(dist[v] = d + w, v);
                seen[v] = 1;
            }
    }
    return {seen, dist};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;

    unordered_map<int, unordered_set<int>> tower_to_dists(n);

    map<int, vi> towers;
    vector<pii> doges;
    map<int, ll> distToDog;
    for (int i = 0; i < m; i++) {
        int b, p; cin >> b >> p;
        tower_to_dists[b].insert(b);
        doges.emplace_back(p, b);
        towers[b].push_back(i);
        distToDog[i] = LLONG_MAX;
    }

    vector<vector<pii>> adjList(m);
    for (int i = 0; i < m; i++) {
        auto dog = doges[i];
        int p = dog.first;
        int b = dog.second;
        bool right = 0, left = 0;
        for (int diff = 0, j = 0; (b + diff < n || b - diff >= 0); diff += p, j++) {
            int r = b + diff;
            int l = b - diff;

            if (!right) {
                for (int dog_idx : towers[r])
                    adjList[i].emplace_back(dog_idx, j);
            }
            if (!left) {
                for (int dog_idx : towers[l])
                    adjList[i].emplace_back(dog_idx, j);
            }
            
            right |= tower_to_dists[r].count(p) || (b + diff >= n);
            left |= tower_to_dists[l].count(p) || (b - diff < 0);
            if (left && right);
                //break;
        }
    }

    auto ans = dijkstra(adjList, 0);
    cout << (ans.first[1] ? ans.second[1] : -1) << endl;

    return 0;
}
