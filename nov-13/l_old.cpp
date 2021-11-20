#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, w;
vector<vi> puzzle;
vector<vector<bool>> solution;

bool place(int row, int col) {
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++)
			if (puzzle[row + dr][col + dc] == 0)
				return false;

	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++)
			puzzle[row + dr][col + dc]--;

	solution[row][col] = true;
	return true;
}

void unplace(int row, int col) {
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++)
			puzzle[row + dr][col + dc]++;
	solution[row][col] = false;
}

bool backtrack(int row, int col) {

	if (row == h - 1) {
		for (int i = 0; i < w; i++)
			if (puzzle[h-1][i] != 0 || puzzle[h-2][i] != 0)
				return false;

		return true;
	}

	if (col == w - 1) {
		for (int i = 0; i < w; i++)
			if (puzzle[row-1][i] != 0)
				return false;

		if (backtrack(row + 1, 1))
			return true;
	}

	// try turning on
	if (place(row, col)) {
		if (backtrack(row, col + 1))
			return true;
		unplace(row, col);
	}


	// don't turn it on
	if (backtrack(row, col + 1))
		return true;

	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> h >> w; h+=2; w+=2;
	puzzle.assign(h, vi(w));
	solution.assign(h, vector<bool>(w, false));
	for (auto &v : puzzle) for (auto &x : v) cin >> x;

	if (backtrack(1, 1)) {
		for (int i = 1; i < h - 1; i++) {
			for (int j = 1; j < w - 1; j++)
				cout << (solution[i][j] ? 'X' : '.');
			cout << endl;
		}
	} else {
		cout << "impossible\n";
	}

	return 0;
}

