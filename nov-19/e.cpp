#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double PI = 3.141592653589793238;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(9);
    
    int n; cin >> n;
    double area = 0;
    for (int i = 0; i < n; i++) {
        double l, w; cin >> l >> w;
        double r = sqrt(l*l/4 + w*w/4);
        double a = PI * r*r;
        area += a;
    }

    cout << area << nl;

    return 0;
}
