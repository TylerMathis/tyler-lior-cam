#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, pii> numToLoc;
map<pii, int> locToNum;

int k;
int best;

void go(pii curLoc, int num, int placed) {
    if (abs(num - k) < abs(best - k)) {
        best = num;
    }

    if (placed == 3) return;
    if ((curLoc != make_pair(3, 1)) &&
        (curLoc.first >= 3 || curLoc.second >= 3))
        return;
    // press button, go down, or go rigiht
    go({curLoc.first + 1, curLoc.second}, num, placed);
    go({curLoc.first, curLoc.second + 1}, num, placed);
    go(curLoc, num*10 + locToNum[curLoc], placed + 1);
}

void solve(int tt) {
    cin >> k;
    int copy = k;

    vi digs;
    while (copy > 0) {
        int dig = copy % 10;
        copy /= 10;

        digs.push_back(dig);
    }
    reverse(all(digs));

    best = INT_MAX;
    go({0, 0}, 0, 0);
    cout << best << nl;
}

    int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);

        int idx = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                numToLoc[idx] = {i, j};
                locToNum[{i, j}] = idx++;
            }
        locToNum[{3, 1}] = 0;
        numToLoc[0] = {3, 1};

        int t; cin >> t;
        for (int tt = 1; tt <= t; tt++)
            solve(tt);

        return 0;
    }

