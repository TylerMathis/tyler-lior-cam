#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a, b; cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << "Not a moose" << endl;
        return 0;
    }
    if (a == b) {
        cout << "Even " << (a+b) << endl;
    } else {
        int mx = max(a, b);
        cout << "Odd " << (2 * mx) << endl;
    }

    return 0;
}
