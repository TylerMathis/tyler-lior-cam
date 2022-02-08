#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n, m; cin >> n >> m;
    int nodes = n * (1 << m);
    vector<vi> adj(nodes);

    vector<vi> values(n, vi(m));
    for (auto &v : values)
        for (auto &x : v)
            cin >> x;
    
    

    return 0;
}