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

    int p, q, n, m;
    cin >> p >> q >> n >> m;

    for (ll r = 0; r <= m; r++) {
        for (ll g = n - r; g <= m - r; g++) {
            ll num = 2*r*g;
            ll den = g*g + r*r + 2*r*g - g - r;
            ll gcd = __gcd(num, den);
            num /= gcd;
            den /= gcd;
            if (num == p && den == q) {
                cout << r << ' ' << g << endl;
                return 0;
            }
        }
    }

    cout << "NO SOLUTION\n";
    return 0;
}

