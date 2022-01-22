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

    int n; cin >> n;
    vector<double> seq(n);
    for (auto &x : seq) cin >> x;

    vector<vector<double>> dp(n, vector<double>(log2(n)));

    for (int b = 0; b < log2(n); b++) {
        for (int u = 0; u < n; u++) {
            if (!b) {
                dp[u][b] = seq[u];
                continue;
            }
            double winChanceSum = 0;
            for (int v = ) {
                if (u == v) continue;
                winChanceSum += (seq[u] / (seq[u] + seq[v]));
            }
            dp[u][b] = winChanceSum * dp[u][b-1];
        }
    }
    cout << dp[0].back() << nl;

    return 0;
}

