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
    int cheapest_idx = 0, cheapest_val = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int price;
        string digits;
        cin >> price >> digits;
        if (price >= cheapest_val) continue;
        map<int, int> found;
        for (char c : digits) {
            found[c - '0']++;
        }
        if (found[2] >= 2 && found[0] >= 1 && found[1] >= 1) {
            cheapest_idx = i;
            cheapest_val = price;
        }
    }

    cout << cheapest_idx << endl;

    return 0;
}
