#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll dists[(1 << 20) + 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k; cin >> n >> k;

    queue<bitset<20>> bfs;
    for (int i = 0; i < n; i++) {
        string val; cin >> val;
        bitset<20> b(val);
        bfs.push(b);
        dists[b.to_ullong()] = 1;
    }

    int maxDist = INT_MIN;
    bitset<20> bestVal;
    while(!bfs.empty()) {
        auto cur = bfs.front();
        int distance = dists[cur.to_ullong()];
        bfs.pop();

        for (int i = 0; i < k; i++) {
            cur.flip(i);
            auto val = cur.to_ullong();
            if (dists[val] == 0) {
                dists[val] = distance + 1;
                bfs.push(cur);
                if (distance + 1 > maxDist) {
                    bestVal = cur;
                    maxDist = distance + 1;
                }
            }
            cur.flip(i);;
        }
    }

    for (int i = k - 1; i >= 0; i--) {
        cout << bestVal[i];
    }
    cout << endl;

    return 0;
}
