#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    ll m, n; cin >> m >> n;
    if (m == 1 && n == 1) {
        cout << 2 << "\n";
        return;
    }
    if (m == 1 && n == 0) {
        cout << 1 << "\n";
        return;
    }
    ll ans = (1LL << m);
    cout << (n == 0 ? ans : ans - 1) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}

