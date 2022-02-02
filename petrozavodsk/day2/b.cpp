#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k; cin >> n >> k;
    if (n == 2) {
        if (k == 1) cout << "YES\n#.\n..\n";
        else if (k == 0) cout << "YES\n..\n..\n";
        else cout << "NO\n";
        return 0;
    }
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string word = "";
        for (int j = 0; j < n; j++)
            if (i == j || k <= 0) word += ".";
            else word += "#", k--;
        ans.push_back(word);
    }
    if (n % 2 == 0) {
        if (ans[n/2-1][n/2] == '#') ans[n/2-1][n/2] = '.', ans[n/2-1][n/2-1] = '#';
        if (ans[n/2][n/2-1] == '#') ans[n/2][n/2-1] = '.', ans[n/2][n/2] = '#';
    }
    if (k > 0) cout << "NO\n";
    else {
        cout << "YES\n";
        for (string s : ans) cout << s << endl;
    }

    return 0;
}