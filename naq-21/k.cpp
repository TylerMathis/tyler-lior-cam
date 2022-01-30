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

    ll m, n;
    cin >> m >> n;

    vi nums(m);
    for (auto &x : nums) cin >> x;
    map<ll, int> suffSumToIdx;

    ll sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum += nums[i];
        suffSumToIdx[sum] = i;
    }

    for (int i = 0; i < n; i++) {
        ll q; cin >> q;
        if (q == 0) {
            cout << "Yes\n";
            continue;
        }
        if (suffSumToIdx.count(q)) {
            cout << "Yes\n";
            continue;
        }
        sum = 0;
        bool found = false;
        for (int i = 0; i < m; i++) {
            sum += nums[i];
            ll comp = q - sum;
            if (comp < 0) break;
            if (comp == 0) {
                cout << "Yes\n";
                found = true;
                break;
            }
            if (suffSumToIdx.count(comp) && suffSumToIdx[comp] > i) {
                cout << "Yes\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "No\n";
    }

    return 0;
}
