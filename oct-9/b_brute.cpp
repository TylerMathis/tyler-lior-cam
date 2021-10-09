#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
ll MAX_PLACE = 1000000;
map<ll, bool> used;
vector<vector<ll>> preRows;
vector<vector<ll>> preCols;
vector<set<int>> rows;
vector<set<int>> cols;

bool valid(int row, int col, int val) {
    if (used[val]) return false;
    if (row == n - 1) {
        double sum = preCols[row - 1][col] + val;
        double av = sum / n;
        int av2 = sum / n;
        if (av != av2) return false;
        if (!cols[col].count(av2)) return false;
    }
    if (col == n - 1) {
        double sum = preRows[row][col - 1] + val;
        double av = sum / n;
        int av2 = sum / n;
        if (av != av2) return false;
        if (!rows[row].count(av2)) return false;
    }
    return true;
}

bool backtrack(vector<vector<ll>> &board, int row, int col) {
    if (col == n) return backtrack(board, row + 1, 0);
    if (row == n) return true;

    // loop up till we can place
    for (int i = 1; i < MAX_PLACE; i++) {
        if (valid(row, col, i)) {
            board[row][col] = i;
            if (row == 0) preCols[row][col] = i;
            else preCols[row][col] = preCols[row - 1][col] + i;
            if (col == 0) preRows[row][col] = i;
            else preRows[row][col] = preRows[row][col - 1] + i;
            rows[row].insert(i);
            cols[col].insert(i);
            used[i] = true;
            if (backtrack(board, row, col + 1))
                return true;
            used[i] = false;
            rows[row].erase(i);
            cols[col].erase(i);
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    vector<vector<ll>> board(n, vector<ll>(n));
    rows = vector<set<int>>(n);
    cols = vector<set<int>>(n);
    preRows = vector<vector<ll>>(n, vector<ll>(n));
    preCols = vector<vector<ll>>(n, vector<ll>(n));
    if (backtrack(board, 0, 0)) {
        for (auto v : board) {
            for (int i : v) cout << i << ' ';
            cout << endl;
        }
    } else cout << -1 << endl;

    return 0;
}
