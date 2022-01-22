#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MAX_NUMS = 5*(int)1e8 + 1;
ll pref[MAX_NUMS];

void solve(int tt) {
    ll k; cin >> k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int num = 1;
    for (int i = 0; i < MAX_NUMS; i++) {
        if (!i) pref[i] = num;
        else pref[i] = pref[i-1] + num;
        num++;
    }

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

