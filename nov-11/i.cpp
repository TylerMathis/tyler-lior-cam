#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> rows;

bool backtrack(int rowIdx) {
	if (rowIdx == sz(rows)) return true;

	int bound = -5;
	int base = rows[rowIdx-1][0] / 2;
	for (int diff = -bound; diff <= bound; diff++) {
		rows[rowIdx][0] = base + diff;
		for (int i = 1; i < sz(rows[rowIdx]); i++) {
			rows[rowIdx][i] = rows[rowIdx-1][i-1] - rows[rowIdx][i-1];
			if (rows[rowIdx][i] < 1) return false;
		}
		if (backtrack(rowIdx + 1))
			return true;
	}

	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, x; cin >> n >> x;
	rows.resize(n);
	for (int i = 1; i < n; i++)
		rows[i].assign(i+1, -1);

	rows[0].push_back(x);
	backtrack(1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(rows[i]); j++) {
			cout << rows[i][j] << ' ';
		}
		cout << nl;
	}

	return 0;
}


