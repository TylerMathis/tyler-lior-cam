#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "cbt"

int getMid(int lo, int hi) {
    int range = hi - lo;
    int highestBit = 31 - __builtin_clz(range);
    int val = 1 << highestBit;
    return lo + val;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    // freopen(filename ".in", "r", stdin);
    // freopen(filename ".out", "w", stdout);

    int n, q; cin >> n >> q;
    int highestBit = 31 - __builtin_clz(n);
    for (int i = 0; i < q; i++) {
        char Q; cin >> Q;
        if (Q == 'A') {

        } else {
            string path; cin >> path;
            int val = getMid(0, n);
        }
    }

    return 0;
}
