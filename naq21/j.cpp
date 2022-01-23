#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<string, int> go(int val) {
    bitset<32> bits(val);

    int leading_bit = 31 - __builtin_clz(val);
    int subs = 0;
    string ops = "1";

    for (int i = leading_bit - 1; i >= 0; i--) {
        ops += "d+";
        subs++;
        if (bits[i]) {
            ops += "1+";
            subs++;
        }
    }
    return {ops, subs};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi stakk(n);
    for (auto &x : stakk) cin >> x;

    vector<string> ans;
    int sub_taken = 0;
    for (int i = n - 1; i >= 0; i--) {
        int val_needed = stakk[i] + sub_taken;
        auto [ops, subs] = go(val_needed);
        ans.push_back(ops);
        sub_taken += subs;
    }

    for (int i = sz(ans) - 1; i >= 0; i--)
        cout << ans[i];
    cout << "\n";

    return 0;
}
