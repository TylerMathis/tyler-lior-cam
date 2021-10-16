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

    int n, k; cin >> n >> k;
    set<int> left, right;

    for (int i = 0; i < n; i++) {
        int at; cin >> at;
        int need = k - at;
        if (left.count(need)) {
            if (right.count(need)) {
                cout << "no" << endl;
                return 0;
            }
            right.insert(at);
        } else {
            left.insert(at);
        }
    }
    cout << "yes" << endl;

    return 0;
}
