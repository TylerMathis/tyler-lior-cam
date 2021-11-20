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

void place(int row, int col) {
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++)
			puzzle[row + dr][col + dc]--;

	solution[row][col] = true;
}

bool solve(int row, int col) {
	if (row == h - 1) {
		for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (puzzle[i][j] != 0)
                    return false;

		return true;
	}

	if (col == w - 1) {
		if (solve(row + 1, 1))
			return true;
        return false;
	}

	if (puzzle[row-1][col-1])
        place(row, col);

    if (solve(row, col + 1))
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

	if (solve(1, 1)) {
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

