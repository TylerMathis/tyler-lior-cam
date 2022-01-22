#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
    typedef uint64_t ull;
    ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
    (A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
    OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
        H operator-(H o) { return *this + ~o.x; }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3;

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string &str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i, 0, sz(str))
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

void solve(int tt) {
    string seq; cin >> seq;

    string rev = seq;
    reverse(all(rev));

    HashInterval forwardsHash(seq), backwardsHash(rev);

    set<pii> seen;
    queue<tuple<int, int, int>> bfs;
    seen.emplace(0, sz(seq));
    bfs.emplace(0, sz(seq), 0);

    while (sz(bfs)) {
        auto [startIdx, endIdx, dist] = bfs.front();
        bfs.pop();

        if (startIdx == endIdx) {
            cout << dist << nl;
            return;
        }

        bool split = false;
        if ((endIdx - startIdx) % 2 == 0) {
            // check if we can split it
            int s = startIdx, e = startIdx + (endIdx - startIdx) / 2;
            auto frontHash =
                forwardsHash.hashInterval(s, e);

            int hi = sz(seq) - startIdx;
            int lo = sz(seq) - endIdx;

            auto backHash =
                backwardsHash.hashInterval(lo, lo + (hi - lo) / 2);

            if (frontHash == backHash) {
                if (seen.insert({s, e}).second)
                    bfs.emplace(s, e, dist + 1);
                split = true;
            }
        }

        if (!split) {
            if (seen.insert({startIdx + 1, endIdx}).second)
                bfs.emplace(startIdx + 1, endIdx, dist + 1);
            if (seen.insert({startIdx, endIdx - 1}).second)
                bfs.emplace(startIdx, endIdx - 1, dist + 1);
        }
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

