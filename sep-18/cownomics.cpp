#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef uint64_t ull;

struct H {
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
	HashInterval(string& str) : ha(sz(str) + 1), pw(ha) {
		pw[0] = 1;
		rep(i, 0, sz(str)) {
			ha[i + 1] = ha[i] * C + str[i];
			pw[i + 1] = pw[i] * C;
		}
	}
	H hashInterval(int a, int b) { // [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;
	vector<string> spotty(n), normal(n);
	for (auto &x : spotty) cin >> x;
	for (auto &x : normal) cin >> x;

	vector<HashInterval> spottyHashes, normalHashes;
	for (int i = 0; i < n; i++) {
		spottyHashes.push_back(HashInterval(spotty[i]));
		normalHashes.push_back(HashInterval(normal[i]));
	}

	int lo = 0, hi = m, len, ans;
	while (lo < hi) {
		int len = lo + hi >> 1;
		unordered_set<ll> spottyHashesOfLen;
		bool winner = false;
		for (int start = 0; start <= m - len; start++) {
			bool valid = true;

			spottyHashesOfLen.clear();
			for (int cow = 0; cow < n; cow++) {
                spottyHashesOfLen.insert(spottyHashes[cow].hashInterval(start, start + len).get());
            }
			
			for (int cow = 0; cow < n; cow++) {
				if (spottyHashesOfLen.count(normalHashes[cow].hashInterval(start, start + len).get())) {
					valid = false;
					break;
				}
            }

			if (valid) {
				winner = true;
				break;
			}
		}

		if (winner) {
			hi = len - 1;
			ans = len;
		} else {
			lo = len + 1;
		}
	}

	cout << ans << endl;

	return 0;
}

