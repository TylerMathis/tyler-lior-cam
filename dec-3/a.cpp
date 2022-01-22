#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int t) {
    int n; cin >> n;
    map<int, int> bitCounts;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        int bit = 0;
        while (val) {
            if (val & 1) bitCounts[bit]++;
            val >>= 1;
            bit++;
        }
    }

    vi counts;
    for (auto [x, y] : bitCounts)
        counts.push_back(y);

    for (int k = 1; k <= n; k++) {
        bool valid = true;
        for (int i : counts) {
            if (i % k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << k << ' ';
        }
    }
    cout << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

