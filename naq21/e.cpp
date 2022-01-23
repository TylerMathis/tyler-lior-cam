#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	int n = size(s);

	int pre = 0;
	int suff = 0;
	bool seen = 0;
	bool closed = 0;
	for (int i = 0; i < n; i++) {
		seen |= s[i] == '(';
		pre += !seen;
		suff += closed;
		closed |= s[i] == ')';
	}
	if (pre == suff)
		cout << "correct\n";
	else
		cout << "fix\n";
	return 0;
}

