#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Hash {
	const int base = 1e9 + 5;
	const vector<int> mods = {(int)1e9+7, (int)1e9+9, (int)1e9+21, (int)1e9+33, (int)1e9+87};
	vector<vector<int>> prefix, powB;

	Hash(const T & s) :
		prefix(mods.size(), vector<int>(s.size() + 1, 0)),
		powB(mods.size(), vector<int>(s.size() + 1, 1)) {
			for (auto val : s) assert(0 < val && val < base);
			for (int i = 0; i < (int) mods.size(); i++) {
				for (int j = 0; j < (int) s.size(); j++) {
					powB[i][j+1] = 1LL * powB[i][j] * base % mods[i];
					prefix[i][j+1] = (1LL * base * prefix[i][j] + s[j]) % mods[i];
				}
			}
		}

	vector<int> getHashes(int L, int R) const {
		assert(0 <= L && L <= R && R+1 < (int) prefix[0].size());
		vector<int> res(mods.size());
		for (int i = 0; i < (int) mods.size(); i++) {
			res[i] = prefix[i][R+1] - 1LL * prefix[i][L] * powB[i][R-L+1] % mods[i];
			if (res[i] < 0) res[i] += mods[i];
		}
		return  res;
	}
};

int n;

int rev(int i) {
	return n - 1 - i;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		n = size(s);
		vector<char> suffMin(n + 1);
		suffMin[n] = 'z';
		for (int i = n - 1; i >= 0; i--)
			suffMin[i] = min(s[i], suffMin[i + 1]);
		int toChange = n;
		for (int i = 0; i < n - 1; i++) {
			if (suffMin[i + 1] < s[i]) {
				toChange = i;
				break;
			}
		}
		if (toChange == n) {
			cout << s << '\n';
			continue;
		}
		vector<int> locs;
		for (int i = toChange + 1; i < n; i++) {
			if (s[i] == suffMin[toChange + 1]) {
				locs.push_back(i);
			}
		}

		string t = s;
		reverse(begin(t), end(t));
		Hash up(s);
		Hash down(t);

		int ear = n;
		char smallest = 'z';
		int locid = 0;
		bool lss = 0;
		int maxPal = 0;


		// for all positions we bin search for the first difference and take the lex smallest
		int i = 0;
		for (auto loc : locs) {
			// we care about the substr [toChange, loc]

			int st = toChange + 1;
			int en = loc - 1;

			int curr = 0;
			for (int e = __lg(n); e >= 0; e--) {
				int mid = curr + (1 << e);

				int i = toChange + mid;
				int j = loc - mid;
				if (i >= j)
					continue;

				if (up.getHashes(st, i) == down.getHashes(rev(en), rev(j)))
					curr = mid;
			}

			if (s[st + curr] != s[en - curr]) {

				if (st + curr <= diffPos && s[en - curr] <= to) {
					diffPos = st + curr;
					to = s[en - curr];
					locid = i;
					lss |= s[en - curr] < s[st + curr];
				}

			} else {
				//assert(st + curr == en - curr);
				maxPal = i;
			}

			i++;
		}

		if (lss) {
			reverse(begin(s) + toChange, begin(s) + locs[locid] + 1);
		} else {
			reverse(begin(s) + toChange, begin(s) + locs[maxPal] + 1);
		}
		cout << s << '\n';
	}
	return 0;
}
