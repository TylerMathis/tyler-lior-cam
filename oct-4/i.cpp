#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "injurious"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

    int n; cin >> n;
    unordered_set<int> exists;
    vector<int> nums(n);
    map<int, int> loc;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        exists.insert(nums[i]);
        loc[nums[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = nums[i] + nums[j];
            if (sum & 1) continue;
            sum /= 2;
            if (exists.count(sum) && loc[sum] > i && loc[sum] < j) {
                cout << "Yes" << endl;
                cout << i+1 << ' ' << loc[sum]+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
