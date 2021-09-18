#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;
// typedef uint64_t ull;

// struct H {
// 	ull x; H(ull x=0) : x(x) {}
// #define OP(O,A,B) H operator O(H o) { ull r = x; asm \
// 	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
// 	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
// 		H operator-(H o) { return *this + ~o.x; }
// 	ull get() const { return x + !~x; }
// 	bool operator==(H o) const { return get() == o.get(); }
// 	bool operator<(H o) const { return get() < o.get(); }
// };
// static const H C = (ll)1e11+3;

// struct HashInterval {
// 	vector<H> ha, pw;
// 	HashInterval(string& str) : ha(sz(str) + 1), pw(ha) {
// 		pw[0] = 1;
// 		rep(i, 0, sz(str)) {
// 			ha[i + 1] = ha[i] * C + str[i];
// 			pw[i + 1] = pw[i] * C;
// 		}
// 	}
// 	H hashInterval(int a, int b) { // [a, b)
// 		return ha[b] - ha[a] * pw[b - a];
// 	}
// };

struct Hash {
	const int base = 257;
	vector<int> mods;
	vector<vector<int>> prefix, powB;

	Hash(const string & s, const vector<int> & currMods) :
		mods(currMods),
		prefix(currMods.size(), vector<int>(s.size())),
		powB(currMods.size(), vector<int>(s.size(), 1)) {
			for (int i = 0; i < (int) mods.size(); i++) {
				for (int j = 1; j < (int) s.size(); j++) {
					powB[i][j] = 1LL * powB[i][j - 1] * base % mods[i];
				}
				int sum = 0;
				for (int j = 0; j < (int) s.size(); j++) {
					sum = (1LL * base * sum + s[j]) % mods[i];
					prefix[i][j] = sum;
				}
			}
		}

	// returns hashes of substring [L, R] inclusive
	vector<int> getHashes(int L, int R) const {
		assert(L <= R);
		vector<int> allHashes;
		for (int i = 0; i < (int) mods.size(); i++) {
			int currHash = prefix[i][R];
			if (L) {
				currHash -= 1LL * prefix[i][L - 1] * powB[i][R - L + 1] % mods[i];
				if (currHash < 0) currHash += mods[i];
			}
			allHashes.push_back(currHash);
		}
		return allHashes;
	}
};

const vector<int> MODS = {(int)1e9 + 7, (int)1e9 + 9};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;
	vector<string> spotty(n), normal(n);
	for (auto &x : spotty) cin >> x;
	for (auto &x : normal) cin >> x;

	vector<Hash> spottyHashes, normalHashes;
	for (int i = 0; i < n; i++) {
		spottyHashes.push_back(Hash(spotty[i], MODS));
		normalHashes.push_back(Hash(normal[i], MODS));
	}

	for (int len = 1; len <= m; len++) {
		unordered_set<ll> spottyHashesOfLen;
		for (int start = 0; start <= m - len; start++) {
			bool valid = true;
			for (int cow = 0; cow < n; cow++) {
                vector<ll> h = spottyHashes[cow].getHashes(start, start + len - 1);
                ll hl = h[0] * MODS[1] + h[1];
                spottyHashesOfLen.insert(hl);
            }
			for (int cow = 0; cow < n; cow++) {
                vector<ll> h = normalHashes[cow].getHashes(start, start + len - 1);
                ll hl = h[0] * MODS[1] + h[1];
				if (spottyHashesOfLen.count(hl)) {
					valid = false;
					break;
				}
            }

			if (valid) {
				cout << len << endl;
				return 0;
			}
		}
	}

	return 0;
}

