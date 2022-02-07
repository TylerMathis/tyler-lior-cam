#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, val = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {
        if (lo != hi) {
            int m = lo + (hi - lo) / 2;
            l = new Node(lo, m);
            r = new Node(m+1, hi);
        }
    }
    int query(int L, int R) {
        if (L > hi || R < lo) return 0;
        if (L >= lo && R <= hi) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (L > hi || R < lo) return;
        if (L >= lo && R <= hi) mset = val = x;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> intervals(m);
    map<int, vector<pii>> heightToInterval;
    map<int, pii> starts, end;
    for (auto &[h, l, r] : intervals) {
        cin >> h >> l >> r;
        heightToInterval[h].emplace_back(l, r);
    }

    for (auto [h, v] : heightToInterval) {
        sort(all(v));
        starts[h].first = v[0].first;
        if (sz(v) > 1) starts[h].second = v[1].first;

        sort(all(v), [&](const auto &a, const auto &b) {
            return a.second < b.second;
        });

        ends[h].first = v[0].second;
        if (sz(v) > 1) ends[h].second = v[1].second;
    }

    // sort by height increasing
    sort(begin(intervals), end(intervals));
    Node tree(0, n+1);
    for (auto &[h, l, r] : intervals)
        tree.set(l, r, h);

    vector<pii> heightLens;
    int curHeight = -1;
    int curLen = 0;
    for (int i = 1; i <= n; i++) {
        int reqHeight = tree.query(i, i);

        if (reqHeight != 0)
            curHeight = reqHeight;

        if (reqHeight == curHeight)
            curLen++;
        else {
            heightLens.emplace_back(curHeight, curLen);
            curLen = 0;
            curHeight = -1;
        }
    }
    if (curHeight != -1) heightLens.emplace_back(curHeight, curLen);

    sort(rbegin(heightLens), rend(heightLens));
    int curX = 0;
    vector<pii> drawnLines; // height, right
    for (auto [h, len] : heightLens) {
        curX += len;
        drawnLines.emplace_back(h, curX);
    }

    for (auto [h, rightMost] : drawnLines) {
        int inter = h - n - rightMost + 1;
        if (inter < 0) {
            int right = -inter;
            right -= max(left[h].second - left[h].first, right[h].second - right[h].first);
            if (right >= 0) {
                cout << "NO\n";
                return 0;
            }
        }
        
        
    }

    return 0;
}