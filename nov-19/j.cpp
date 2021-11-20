#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll&y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

const ll mod = 1000000007;

// ll modpow(ll b, ll e) {
//     ll ans = 1;
//     for (; e; b = b * b % mod, e /= 2)
//         if (e & 1) ans = ans * b % mod;
//     return ans;
// }

struct Mod {
    ll x;
    Mod() : x(1) {}
    Mod(ll xx) : x(xx) {}
    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
    Mod operator/(Mod b) { return *this * invert(b); }
    Mod invert(Mod a) {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1); return Mod((x + mod) % mod);
    }
    Mod operator^(ll e) {
        if (!e) return Mod(1);
        Mod r = *this ^ (e / 2); r = r * r;
        return e&1 ? *this * r : r;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int x, y, n; cin >> x >> y >> n;
    

    Mod fac[n+1];
    for (Mod i(1); i.x <= n; i.x++)
        fac[i.x] = fac[i.x - 1] * i;

    Mod ans(0);
    for (int xs = 0; xs <= n; xs++) {
        ll sum = xs * x + (n - xs) * y;
        int dig; bool valid = true;
        while (sum) {
            dig = sum % 10;
            sum /= 10;
            if (!(dig == x || dig == y)) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        // bin = (n choose xs)
        Mod nFac = fac[n];
        Mod den = (fac[xs] * fac[n - xs]);
        ans = ans + (nFac / den);
    }

    cout << ans.x << nl;

    return 0;
}
