#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void win(int player) {
    if (player == 1) cout << "X wins\n";
    else cout << "O wins\n";;
}

void solve(int tc) {
    string val; cin >> val;
    ll dec = 0;
    ll pw = 1;
    for (int i = sz(val) - 1; i >= 0; i--) {
        dec += (val[i] - '0') * pw;
        pw *= 8;
    }

    bitset<64> bits(dec);
    int grid[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = 0;
        
    // for (int i = 0; i < 64; i++) {
    //     cout << bits[i] << ' ';
    // } cout << nl;
    
    int found = 0;
    for (int i = 0; i < 9; i++) {
        if (!bits[i]) continue;
        found++;
        int row = i / 3;
        int col = i % 3;
        int checkBit = i + 9;
        if (bits[checkBit])
            grid[row][col] = 1;
        else grid[row][col] = -1;
    }

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << grid[i][j] << ' ';
    //     }
    //     cout << nl;
    // }

    // Check for cols
    for (int c = 0; c < 3; c++) {
        int type = grid[0][c];
        if (type == 0) continue;
        bool good = true;
        for (int r = 0; r < 3; r++) {
            if (grid[r][c] != type) {
                good = false;
                break;
            }
        }
        if (good) {
            win(type);
            return;
        }
    }

    // Check for rows
    for (int r = 0; r < 3; r++) {
        int type = grid[r][0];
        if (type == 0) continue;
        bool good = true;
        for (int c = 0; c < 3; c++) {
            if (grid[r][c] != type) {
                good = false;
                break;
            }
        }
        if (good) {
            win(type);
            return;
        }
    }

    // Check diags
    int type = grid[0][0];
    bool good = false;
    if (type != 0) {
        good = true;
        for (int i = 0; i < 3; i++) {
            if (grid[i][i] != type) {
                good = false;
                break;
            }
        }
    }

    if (good) {
        win(type);
        return;
    };

    int row = 2, col = 0;
    type = grid[row][col];
    good = false;
    if (type != 0) {
        good = true;
        for (int i = 0; i < 3; i++) {
            if (grid[row][col] != type) {
                good = false;
                break;
            }
            row--;
            col++;
        }
    }

    if (good) {
        win(type);
        return;
    };

    if (found == 9) {
        cout << "Cat's\n";
        return;
    }

    cout << "In progress\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}
