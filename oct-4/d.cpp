#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "domino"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin);
    freopen(filename ".out", "w", stdout);

    int k, r; cin >> k >> r;

    vector<pii> bones(k);
    int penalty = 0;
    for (auto &[x, y] : bones)
        cin >> x >> y, penalty += x + y;

    vector<int> sequence(2*r);
    for (auto &x : sequence) cin >> x;

    int left = sequence[0];
    int right = sequence[2*r - 1];

    bool leftFound = false;
    bool rightFound = false;
    bool win = false;

    if (left == right) {
        for (auto [x, y] : bones) {
            if (x == y && x == left) {
                if (leftFound) rightFound = true;
                leftFound = true;
            }
        }
    } else {
        for (auto [x, y] : bones) {
            if (x == y && x == left) {
                leftFound = true;
            } else if (x == y && x == right) {
                rightFound = true;
            }
        }
    }

    int doublesRemoved = INT_MAX;
    if (leftFound && rightFound) {
        doublesRemoved = penalty - 2 * (left + right);
        win |= (k - 2 == 0);
    }

    // try putting on left or right
    int bestSum = 0;
    for (auto [x, y] : bones) {
        if (x == left || y == left) {
            bestSum = max(bestSum, x + y);
        }
        if (x == right || y == right) {
            bestSum = max(bestSum, x + y);
        }
    }
    int singleRemoved = penalty - bestSum;
    if (bestSum > 0) win |= (k - 1 == 0);
    
    if (win) cout << -1 << endl;
    else cout << min(singleRemoved, doublesRemoved) << endl;

    return 0;
}
