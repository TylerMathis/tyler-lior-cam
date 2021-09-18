#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct stree {
    int val, l, r, m;
    stree *lc, *rc;

    stree(int lo, int hi) {
        val = 0;
        l = lo;
        r = hi;
        m = lo + hi >> 1;

        if (l != r) {
            lc = new stree(l, m);
            rc = new stree(m+1, r); 
        }
    }

    int query(int lo, int hi) {
        // no
        if (lo > r || hi < l) return 0;
        // full
        if (lo <= l && hi >= r) return val;
        return max(lc->query(lo, hi), rc->query(lo, hi));
    }

    void set(int idx, int v) {
        // no
        if (idx < l || idx > r) return;
        // full
        if (l == r) val = v;
        lc->set(idx, v);
        rc->set(idx, v);

        val = max(lc->val, rc->val);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto & x : a)
		cin >> x;

    stree lis(0, 50);
    vector<int> rev = a;
    reverse(all(rev));
    for (int i : rev) {
        int mx = lis.query(0, i-1);
        lis.set(i, mx+1);
    }

    
}
