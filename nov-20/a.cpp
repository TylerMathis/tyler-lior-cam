#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vector<string>> nums = {
    {0, {
        "xxxxx",
        "x...x",
        "x...x",
        "x...x",
        "x...x",
        "x...x",
        "xxxxx"
    }},
    {1, {
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x"
    }},
    {2, {
        "xxxxx",
        "....x",
        "....x",
        "xxxxx",
        "x....",
        "x....",
        "xxxxx"
    }},
    {3, {
        "xxxxx",
        "....x",
        "....x",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx"
    }},
    {4, {
        "x...x",
        "x...x",
        "x...x",
        "xxxxx",
        "....x",
        "....x",
        "....x"
    }},
    {5, {
        "xxxxx",
        "x....",
        "x....",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx"
    }},
    {6, {
        "xxxxx",
        "x....",
        "x....",
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx"
    }},
    {7, {
        "xxxxx",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x",
        "....x"
    }},
    {8, {
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx"
    }},
    {9, {
        "xxxxx",
        "x...x",
        "x...x",
        "xxxxx",
        "....x",
        "....x",
        "xxxxx"
    }}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    vector<string> inp(7);
    for (auto &x : inp) cin >> x;

    ll total = 0, curNum = 0;
    const int width = 6;
    int numNumbers = (sz(inp[0])+1) / width;
    for (int idx = 0; idx < numNumbers; idx++) {
        vector<string> val(7);
        for (int i = 0; i < 7; i++)
            val[i] = inp[i].substr(idx*width, width-1);
        int num = 0;
        for (num; nums[num] != val && num <= 9; num++);
        if (num == 10) {
            total += curNum;
            curNum = 0;
        } else {
            curNum *= 10;
            curNum += num;
        }
    }

    total += curNum;
    
    vector<vector<string>> ans;
    if (total == 0) {
        ans.push_back(nums[0]);
    }
    while (total > 0) {
        int dig = total % 10;
        total /= 10;
        ans.push_back(nums[dig]);
    }

    for (int i = 0; i < 7; i++) {
        for (int j = sz(ans) - 1; j >= 0; j--) {
            cout << ans[j][i];
            if (j) cout << '.';
        }
        cout << nl;
    }

    return 0;
}
