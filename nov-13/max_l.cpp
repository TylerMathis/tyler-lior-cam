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

    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            cout << (int)rand() % 10 << ' ';
        }
        cout << endl;
    }

    return 0;
}
