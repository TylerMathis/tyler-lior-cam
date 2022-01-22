#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) {
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s) + 1);
		vi y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i, 0, n) ws[x[i]]++;
			rep(i, 1, lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i, 1, n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i, 1, n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = size(s);
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
		string t = s;
		reverse(begin(t), end(t));
		for (int cnt = 0, i = n - 1; cnt < toChange && i >= 0; i--, cnt++)
			t.pop_back();
		for (auto & ch : t)
			ch = 'z' - (ch - 'a');

		int last = 0;
		for (int i = 0; i < toChange; i++, last++)
			cout << s[i];

		SuffixArray suffArr(t);

		int cnt = 0;
		for (int i = suffArr.sa.size() - 1; i >= 0; i--) {
			cout << i << ' ' << suffArr.sa[i] << ' ';
			for (int j = suffArr.sa[i]; j < (int) size(t); j++)
				cout << char('z' - (t[j] - 'a'));
			cout << '\n';
			cnt++;
			if (cnt > 10) {
				break;
			}
		}

		for (int i = suffArr.sa.size() - 1; i >= 0; i--) {
			int x = suffArr.sa[i];
			if ('z' - (t[x] - 'a') == suffMin[toChange + 1]) {
				cout << i << '\n';
				while (i >= 1 && suffArr.lcp[i] == (int) size(t) - suffArr.sa[i - 1]) {
					i--;
					x = suffArr.sa[i];
				}
				cout << i << '\n';
				x = suffArr.sa[i];


				for (int j = x; j < (int) size(t); j++, last++)
					cout << char('z' - (t[j] - 'a'));
				break;
			}
		}
		while (last < n) {
			cout << s[last];
			last++;
		}
		cout << '\n';
	}
	return 0;
}
