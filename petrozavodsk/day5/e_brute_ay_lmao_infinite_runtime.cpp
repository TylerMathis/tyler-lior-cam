#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> mat(4, vi(4));

bool check() {
    set<int> sums;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            sums.insert(mat[r][c] + mat[r+1][c] + mat[r][c+1] + mat[r+1][c+1]);
            if (sz(sums) > 1) return false;
        }
    }
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            cout << mat[r][c] << ' ';
        }
        cout << endl;
    }
    return true;
}

vector<bool> used(16, false);
bool brute(int r, int c) {
    if (r == 4)
        return check();

    if (c == 4) return brute(r + 1, 0);

    for (int d = 1; d <= 16; d++) if (!used[d]) {
        mat[r][c] = d;
        used[d] = true;
        if (brute(r, c+1)) return true;
        used[d] = false;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    brute(0, 0);
    
    return 0;
}