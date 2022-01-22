#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tt) {
    int n; cin >> n;
    vi seq(n);
    for (auto &x : seq) cin >> x;

    deque<int> cur = {seq[0]};
    string ans = "r";

    for (int i = 1; i < n; i++) {
        int newVal = seq[i];
        int beginning = cur[0];
        int end = cur.back();

        int begSmaller = beginning < end;
        if (begSmaller) {
            if (newVal <= beginning) {
                cur.push_front(newVal);
                ans += "l";
            } else {
                cur.push_back(newVal);
                ans += "r";
            }
        } else {
            if (newVal <= end) {
                cur.push_back(newVal);
                ans += "r";
            } else {
                cur.push_front(newVal);
                ans += "l";
            }
        }

        // check if the left or right compress
        while (sz(cur) > 1 && (cur[0] == cur[1] || cur[sz(cur)-1] == cur[sz(cur)-2])) {
            while (sz(cur) > 1 && cur[sz(cur)-1] == cur[sz(cur)-2]) {
                cur.pop_back();
                cur[sz(cur)-1] *= 2;
            }
            while (sz(cur) > 1 && cur[0] == cur[1]) {
                cur.pop_front();
                cur[0] *= 2;
            }
        }
    }

    if (sz(cur) == 1) {
        cout << ans << nl;
    } else {
        cout << "no" << nl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
        solve(tt);

    return 0;
}

