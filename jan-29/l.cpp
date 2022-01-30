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

    string in; cin >> in;
    map<char, vi> locs;
    for (int i = 0; i < sz(in); i++) {
        locs[in[i]].push_back(i);
    }

    for (auto [_, v]: locs) {
        if (sz(v) >= 3) {
            cout << "NO\n";
            return 0;
        }

        if (sz(v) == 2) {
            if ((v[1] - v[0] + 1) & 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}

