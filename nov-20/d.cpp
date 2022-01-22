#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1000000007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k; cin >> n >> k;
    string str; cin >> str;

    ll bars = 0;
    ll num = 0;
    bool foundLastBar = false;
    for (int i = 0; i < n; i++) {
        num *= 10;
        num += str[i] - '0';
        num %= k;
        if (!num) {
            if (i == n - 1) foundLastBar = true;
            else bars++;
        }
    }

    if (!foundLastBar) {
        cout << 0 << nl;
        return 0;
    }

    ll ans = 1;
    for (int i = 0; i < bars; i++) {
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
