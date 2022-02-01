#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> days(n);
    for (auto &x : days) cin >> x;
    int t; cin >> t;

    set<int> classes;
    for (auto x : days) {
        classes.insert(x/t*t);
    }

    cout << (int)classes.size() << endl;

    return 0;
}