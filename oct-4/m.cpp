#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "munich"

int m, n, k;

ll go(int a, int c, int a5) {
    ll cost = 0;
    int ac = m, cc = n;
    
    if (c > a) c = a;
    if (5 * a > a5) {
        int take = ac / 5;
        ac -= take * 5;
        cost += take * a5;
    }

    if (5 * c > a5) {
        int take = cc / 5;
        cc -= take * 5;
        cost += take * a5;
    }

    // now we have some left-over children and adults
    // if either of them are less than 5, check if we can combine for a cheap ticket
    if (ac < 5) {
        int indi = ac * a + (5 - ac) * c;
        if (indi > a5) {
            ac = 0;
            cc -= (5 - ac);
            cost += a5;
        }
    } else if (cc < 5) {
        int indi = cc * c + (5 - cc) * a;
        if (indi > a5) {
            cc = 0;
            ac -= (5 - cc);
            cost += a5;
        }
    }

    // buy everything else
    cost += ac * a + cc * c;
    return cost;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

    cin >> m >> n >> k;
    int p1, p2, p3; cin >> p1 >> p2 >> p3;
    int q1, q2, q3; cin >> q1 >> q2 >> q3;

    ll mi = LLONG_MAX;
    mi = min(mi, go(p1, p2, p3) * k);
    mi = min(mi, go(q1, q2, q3));

    cout << mi << endl;

    return 0;
}
