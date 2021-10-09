#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct stree {
    int l, r, m, val = 0;
    stree *left, *right;

    stree(int lo, int hi) {
        l = lo;
        r = hi;
        m = lo + hi >> 1;
        if (l != r) {
            left = new stree(l, m);
            right = new stree(m + 1, r);
        }
    }

    void set(int idx, int nval) {
        if (l == r) val = nval;
        else {
            if (idx <= m) left->set(idx, nval);
            else right->set(idx, nval);
            val = left->val + right->val;
        }
    }

    int query(int lo, int hi) {
        // no cover
        if (lo > r || hi < l) return 0;
        // full cover
        if (lo <= l && hi >= r) return val;
        // partial
        return left->query(lo, hi) + right->query(lo, hi);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi nums(n);
    for (auto &x : nums) cin >> x;

    map<int, int> comp;
    vi sorted = nums;
    sort(all(sorted));
    for (int i = 0; i < n; i++) {
        comp[sorted[i]] = i;
    }

    stree prefix(0, n-1), suffix(0, n-1);

    for (int i : nums) {
        suffix.set(comp[i], 1);
    }

    ll sum = 0;
    for (int i : nums) {
        prefix.set(comp[i], 1);
        suffix.set(comp[i], 0);
        int l = prefix.query(comp[i] + 1, n-1);
        int r = suffix.query(comp[i] + 1, n-1);
        if (l > r * 2 || r > l * 2) sum++;
    }

    cout << sum << endl;

    return 0;
}
