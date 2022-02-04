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

    int n, k; cin >> n >> k;
    vector<int> curStats(n);
    unordered_map<string, int> names;
    names.reserve(n);
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names[name] = sz(names);
        cin >> curStats[i];
    }

    int m; cin >> m;
    vector<int> maxRequired(n);
    vector<vector<int>> events(n);
    for (int i = 0; i < m; i++) {
        string name; int stat;
        cin >> name >> stat;
        maxRequired[names[name]] = max(maxRequired[names[name]], stat);
        events[names[name]].push_back(stat);
    }

    for (int i = 0; i < n; i++) {
        if (curStats[i] < maxRequired[i]) {
            ll required = maxRequired[i] - curStats[i];
            k -= required;
            if (k < 0) {
                cout << 0 << endl;
                return 0;
            }

            curStats[i] = maxRequired[i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (ll cost : events[i])
            if (curStats[i] > cost)
                ans += curStats[i];
    }

    priority_queue<pair<ll, int>> benefits;
    for (int i = 0; i < n; i++) {
        ll benefit = 0;
        for (ll cost : events[i]) {
            if (cost == curStats[i])
                benefit += curStats[i];
            benefit++;
        }
        benefits.emplace(benefit, i);
    }

    int lastID = -1;
    while (k > 0) {
        auto [benefit, id] = benefits.top();
        benefits.pop();

        // We've seen it before, use the rest of our k's on it
        if (id == lastID) {
            ans += k * benefit;
            cout << ans << endl;
            return 0;
        }

        lastID = id;

        ans += benefit;
        k--;


        // Now put it back in queue
        benefits.emplace(sz(events[id]), id);
    }

    cout << ans << endl;

    return 0;
}