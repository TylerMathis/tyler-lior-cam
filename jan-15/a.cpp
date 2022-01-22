#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<tuple<int, int, int>> nodes;
int rec(int a, int b) {
    if (a == 0 && b == 0) return 0;
    int id = sz(nodes) + 1;
    nodes.emplace_back();
    if (b > 0) {
        get<0>(nodes.back()) = 2;
        b--;
    } else {
        get<0>(nodes.back()) = 1;
        a--;
    }

    int bl = b / 2;
    int al = a / 2;
    int br = b - bl;
    int ar = a - al;

    int leftSum = al + 2 * bl;
    int rightSum = ar + 2 * br;
    if (leftSum < rightSum - 1) {
        if (ar > 0) {
            al++;
            ar--;
        } else {
            cout << -1 << endl;
            exit(0);
        }
    }

    get<1>(nodes[id-1]) = rec(al, bl);
    get<2>(nodes[id-1]) = rec(ar, br);

    return id;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int a, b; cin >> a >> b;
    rec(a, b);

    for (auto &[val, left, right] : nodes)
        cout << val << ' ' << left << ' ' << right << endl;

    return 0;
}
