#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct alien {
    int a, b, d;
    alien(int a, int b, int d) : a(a), b(b), d(d) {}
    bool operator<(const alien &o) const {
        return b < o.b;
    }
};

void solve(int tt) {
    int k; cin >> k;
    vector<alien> aliens;
    for (int i = 0; i < k; i++) {
        int a, b, d; cin >> a >> b >> d;
        aliens.emplace_back(a, b, d);
    }
    sort(all(aliens));

    vi times;
    vector<vector<alien>> compressed;
    for (auto a : aliens) {
        if (sz(times) == 0 || a.b != times.back()) {
            times.push_back(a.b);
            compressed.emplace_back();
        }
        compressed.back().push_back(a);
    }

    map<int, int> compressedRads;
    vi actualRads;
    for (auto a : aliens)
        if (!compressedRads.count(a.d)) {
            compressedRads[a.d] = sz(compressedRads);
            actualRads.push_back(a.d);
        }

    int numTimes = sz(times);
    vector<vector<ll>> dp(numTimes+5, vector<ll>(sz(compressedRads)+5, LLONG_MAX));
    auto go = [&](int timeStep, int lastRad, auto &&go) -> ll {
        if (timeStep == numTimes) return 0;

        auto &ans = dp[timeStep][lastRad];
        if (ans != LLONG_MAX) return ans;

        int actualLastRad = actualRads[lastRad];
        int curTime = compressed[timeStep].back().b;
        int lastTime = timeStep > 0 ? compressed[timeStep-1].back().b : INT_MIN;

        int lo = -1;
        for (auto &a : compressed[timeStep])
            if (!(a.a <= lastTime && a.d <= actualLastRad))
                if (lo == -1 || actualRads[lo] < a.d)
                    lo = compressedRads[a.d];

        set<int> radsToTry;
        if (lo != -1) radsToTry.insert(actualRads[lo]);

        for (auto &a : aliens)
            if ((a.a <= curTime && curTime <= a.b) && !(a.a <= lastTime && a.d <= actualLastRad))
                if (lo == -1 || actualRads[lo] < a.d)
                    radsToTry.insert(a.d);

        // cout << timeStep << nl;
        // for (int i : radsToTry) cout << i << ' ';
        // cout << nl << nl;

        if (sz(radsToTry) == 0) {
            return ans = go(timeStep + 1, 0, go);
        } else {
            for (int rad : radsToTry)
                ans = min(ans, go(timeStep + 1, compressedRads[rad], go) + rad);
        }

        return ans;
    };

    cout << go(0, 0, go) << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}
