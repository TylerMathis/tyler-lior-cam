#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
    ll n; cin >> n;

    int curLen = 1;
    int curIter = 1;
    ll curPow = 1;
    int longestRun = 0;
    while (curLen < n) {
        curLen += (curIter++) * curPow;
        curPow *= 2;
        longestRun++;
    }

    cout << longestRun << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}

