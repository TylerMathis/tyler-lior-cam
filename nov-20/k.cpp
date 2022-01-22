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

    int n; cin >> n;
    vi attack(2*n);
    for (auto &x : attack) cin >> x, x--;

    vi ind(2*n, 0);
    for (auto x : attack) ind[x]++;

    vector<bool> kernel(2*n, false);
    for (int i = 0; i < n; i++) kernel[i] = true;

    queue<int> q;
    for (int i = n; i < 2*n; i++) if (!ind[i]) q.push(i);

    while (q.size()) {
        int top = q.front();
        kernel[top] = true;
        q.pop();

        int attacks = attack[top];
        if (kernel[attacks]) {
            kernel[attacks] = false;
            int removed = attack[attacks];
            if (--ind[removed] == 0)
            q.push(removed);
        }
    }

    for (int i = 0; i < 2*n; i++)
        if (kernel[i]) cout << i + 1 << ' ';
    cout << nl;

    return 0;
}
