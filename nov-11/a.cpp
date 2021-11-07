#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct seg {
	int val = INT_MAX, l, r, m;
	seg *left, *right;
	seg(int lo, int hi) {
		l = lo;
		r = hi;
		m = (l + r) >> 1;
		if (l != r) {
			left = new seg(l, m);
			right = new seg(m + 1, r);
		}
	}

	void set(int idx, int nval) {
		if (l == r) val = min(val, nval);
		else {
			if (idx <= m) left->set(idx, nval);
			else right->set(idx, nval);
			val = min(left->val, right->val);
		}
	}

	int query(int lo, int hi) {
		if (hi < l || lo > r) return INT_MAX;
		if (lo <= l && hi >= r) return val;
		return min(left->query(lo, hi), right->query(lo, hi));
	}
};

struct thing {
	int width, mass, idx;
	bool operator<(const thing &o) const {
		return mass < o.mass;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int s; cin >> s;
	vector<thing> slots(s);
	int i = 1;
	for (auto &[x, y, z] : slots) {
		cin >> x >> y;
		z = i++;
	}

	int c; cin >> c;
	vector<thing> coins(c);
	for (auto &[x, y, z] : coins) cin >> x >> y;

	sort(all(slots));
	sort(all(coins));

	seg tree(0, 100'000);

	int slotIdx = 0;
	ll total = 0;
	for (int i = 0; i < c; i++) {
		int width = coins[i].width;
		int mass = coins[i].mass;

		while (slotIdx < s && slots[slotIdx].mass <= mass) {
			tree.set(slots[slotIdx].width, slots[slotIdx].idx);
			slotIdx++;
		}

		total += tree.query(width, 100'000);
	}

	cout << total << endl;

	return 0;
}

