#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
    pair<int, int> no = {0, 0};
};

struct SegmentTree {
    vector<Node> tree;
    int n;

    Node combineChildren(const Node &L, const Node &R) {
        return Node {
            max(L.no, R.no)
        };
    }

    SegmentTree(int currSize) : n(currSize) {
        int size = 1;
        while(size < n) size<<=1;
        size<<=1;
        tree.resize(size);
    }
    void update(int l, int r, int val) {update(1, 0, n-1, l, r, val);}
    void update(int node, int start, int end, int l, int r, int val) {
        if(r < start || end < l) return;
        if(l <= start && end <= r) {
            if (l == r)
                assert(start == end);
            tree[node].no.first = max(tree[node].no.first, val);
            tree[node].no.second = start;
            return;
        }
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r, val);
        update(2*node+1, mid+1, end, l, r, val);
        tree[node] = combineChildren(tree[2*node], tree[2*node+1]);
    }
    Node query(int l, int r) {return query(1, 0, n-1, l, r);}
    Node query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return Node();
        if(l <= start && end <= r) return tree[node];
        int mid = (start+end)/2;
        return combineChildren(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x;
    reverse(all(a));

    vi dp(n+10);
    vector<pii> par(n+10, {-1, -1});
    SegmentTree tree(n + 10);
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        tree.update(n-i-1, n-i-1, max(0, n-i-1-val));
    }
    tree.update(n, n, n);
    queue<int> bfs;
    bfs.push(0);

    while(sz(bfs)) {
        int i = bfs.front();
        bfs.pop();
        int lo = i+1;
        int hi = i+a[i];

        pii q = tree.query(lo, hi).no;
        while (q.first > 0) {
            q = tree.query(lo, hi).no;
            tree.update(q.second, q.second, 0);
            dp[q.first] = dp[i] + 1;
            par[q.first] = {i, q.second};
            bfs.push(q.first);
        }
    }

    if (par[n].first == -1) {
        cout << -1 << nl;
        return 0;
    }

    vi ans;
    for (int idx = n; idx > 0; idx = par[idx].first)
        ans.push_back(par[idx].second);

    cout << dp[n] << nl;
    reverse(all(ans));
    for (int i : ans)
        cout << n - i << ' ';
    cout << nl;

    return 0;
}
