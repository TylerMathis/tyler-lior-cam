#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;

    MCMF(int N) :
    N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
    seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;

        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});

        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };

        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            for (int i : ed[s]) if (!seen[i])
                relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i : red[s]) if (!seen[i])
                relax(i, flow[i][s], cost[i][s], 0);
        }
        rep(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p, r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i,0,N) rep(j,0,N) {
            if (flow[i][j] > 0) {
                totcost += cost[i][j];
                // cout << cost[i][j] << ' ';
            }
        } 
        return {totflow, totcost};
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> prices(m);
    vector<vi> bundles(m);
    for (int i = 0; i < m; i++) {
        int price, num; cin >> price >> num;
        prices[i] = price;
        for (int j = 0; j < num; j++) {
            int candy; cin >> candy; candy--;
            bundles[i].push_back(candy);
        }
    }

    int s = m+n;
    int t = s+1;
    MCMF flow(m+n+2);
    for (int i = 0; i < m; i++) {
        // cout << "connecting " << s << " to " << i << endl;
        flow.addEdge(s, i, INF, prices[i]);
        for (int c : bundles[i]) {
            // cout << "connecting " << i << " and " << m + c << endl;
            flow.addEdge(i, m + c, 1, 0);
        }
    }

    for (int i = 0; i < n; i++) {
       // cout << "connecting " << i+m << " to " << t << endl;
        flow.addEdge(i+m, t, 1, 0);
    }

    auto ans = flow.maxflow(s, t);
    //cout << "Flow: " << ans.first << endl;
     cout << "Cost: " << ans.second << endl;
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 0; tt < t; tt++) solve();

    return 0;
}

