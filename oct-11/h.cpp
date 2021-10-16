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

    int n; cin >> n;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;

    vector<vi> dp(n, vi(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = dp[i][j-1];
            else if (j == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]);

            if (grid[i][j] == '0') dp[i][j]++;
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}
