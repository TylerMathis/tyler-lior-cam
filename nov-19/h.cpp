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
    ll maxSide = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll l, w; cin >> l >> w;
        sum += min(l, w);
        maxSide = max(maxSide, max(l, w));
    }
    maxSide = max(maxSide, sum);

    cout << maxSide << nl;

    return 0;
}
