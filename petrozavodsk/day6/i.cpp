#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct Transaction {
    int m, p;
    Transaction(int m, int p) : m(m), p(p) {}
    int get() const { return m - p; }
    bool operator<(const Transaction &a) const { return make_pair(get(), p) < make_pair(a.get(), a.p); }
    bool operator<(const int &b) const { return get() < b; }
    bool operator==(const Transaction &a) const { return tie(m, p) == tie(a.m, a.p); }
};

void solve() {
    int t; cin >> t;
    vector<tuple<int, int, int>> queries;
    vector<Transaction> transactions;
    for (int i = 0; i < t; i++) {
        int t, m, p;
        t = m = p = -1;
        cin >> t >> m;
        if (t != 3) {
            cin >> p;
            transactions.emplace_back(m, p);
        }
        queries.emplace_back(t, m, p);
    }
    sort(all(transactions));
    transactions.erase(unique(all(transactions)), end(transactions));

    vi transactionFreq(sz(transactions));
    Tree m_seg(sz(transactions)), p_seg(sz(transactions));
    for (auto &[t, m, p] : queries) {
        if (t == 3) {
            int b = m;
            int split = lower_bound(all(transactions), b) - begin(transactions);
            int left = m_seg.query(0, split);
            int right = p_seg.query(split, sz(transactions)) + b;
            cout << max(left, right) << "\n";
        } else {
            int idx = lower_bound(all(transactions), Transaction(m, p)) - begin(transactions);
            if (t == 1) {
                if (++transactionFreq[idx] == 1) {
                    m_seg.update(idx, m);
                    p_seg.update(idx, p);
                }
            } else {
                if (--transactionFreq[idx] == 0) {
                    m_seg.update(idx, INT_MIN);
                    p_seg.update(idx, INT_MIN);
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}