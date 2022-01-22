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
    for (int i = 0; i < n; i++) {
        ll b, d; cin >> b >> d;
        ll gcd = __gcd(b, d);
        ll ans = b / (d / gcd);
        if (b % (d / gcd) == 0)
            ans--;
        cout << ans << endl;
    }

    return 0;
}
