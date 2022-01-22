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

    int n; cin >> n;
    map<int, int> lastSeenVal;
    set<int> signsTaken;
    bool signTaken = false;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k > 0) signTaken = true;
        vi people(k);
        for (auto &x : people) cin >> x;
        int minDayNeeded = n;
        for (int p : people) {
            if (lastSeenVal[p] == 0) continue;
            minDayNeeded = min(minDayNeeded, lastSeenVal[p] - 1);
        }
        signsTaken.insert(minDayNeeded);
        for (int p : people)
            lastSeenVal[p] = minDayNeeded;
    }

    cout << (signTaken ? signsTaken.size() : 0) << endl;

    return 0;
}
