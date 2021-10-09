#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "a"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

    int n; cin >> n;
    double mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int dx = abs(c-a);
        int dy = abs(d-b);
        double ratio = (double)(dx*dy) / (2*dx + 2*dy);
        mx = max(ratio, mx);
    }

    cout << mx << endl;

    return 0;
}
