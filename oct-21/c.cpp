#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<bool> beds(n, false);
    beds[0] = true;

    int idx = 0;
    int jmp = 1;
    while (true) {
        idx += jmp++;
        idx %= n;
        if (beds[idx])
            break;
        beds[idx] = true;
    }

    bool valid = true;
    for (bool b : beds)
        valid &= b;
    
    if (valid) cout << "YES";
    else cout << "NO";
    cout << endl;

    return 0;
}
