#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())
typedef long long ll;

using namespace std;

int main() {
    int n; cin >> n;
    int len = (1 << n);
    vector<int> vals(len);
    for (auto &x : vals) cin >> x;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n; j++) {
            int next = i + (1 << j);
            if (next < i || next >= len) continue;
            if (vals[i] + vals[next] < vals[i&next] + vals[i|next]) {
                cout << i << ' ' << next << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}