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

    int t, s, n; cin >> t >> s >> n;

    int sandInBottom = s;
    int lastFlip = 0;
    for (int i = 0; i < n; i++) {
        int flipTime; cin >> flipTime;
        int diff = flipTime - lastFlip;

        // flowing up
        if (i & 1) {
            sandInBottom = max(0, sandInBottom - diff);
        } else {
            sandInBottom = min(s, sandInBottom + diff);
        }

        lastFlip = flipTime;
    }

    int diff = t - lastFlip;
    // sand in bottom
    if (n & 1) {
        sandInBottom = max(0, sandInBottom - diff);
        cout << sandInBottom << endl;
    } else {
        sandInBottom = min(s, sandInBottom + diff);
        cout << s - sandInBottom << endl;
    }

    return 0;
}
