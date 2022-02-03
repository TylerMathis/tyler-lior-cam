#include <bits/stdc++.h>
using namespace std;

const int UPPER = 10;

vector<vector<int>> g;
set<int> chosen;
int colored = 0;

int dfs(int u) {
    if (g[u].size() == 0) return 1;
    int leaves = 0;
    for (auto &v : g[u])
        leaves += dfs(v);
    if (leaves > 1) {
        cout << "PLACED" << endl;
        chosen.insert(u);
        leaves = 0;
    }
    return leaves;
}

void solve(vector<vector<int>> tree) {
    g = tree;
    colored = 0;
    dfs(0);
}

void check(vector<vector<int>> graph) {
    // get all leaves
    set<int> leaves;
    for (int i = 1; i < (int)graph.size(); i++)
        if ((int)graph[i].size() == 1)
            leaves.insert(i);

    for (int i : leaves) cout << i+1 << ' ';
    cout << endl;

    for (int leaf : leaves) {
        queue<int> bfs;
        vector<bool> visited((int)graph.size(), false);
        bfs.push(leaf);
        visited[leaf] = true;
        while (!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            for (int x : graph[cur]) {
                if (visited[x]) continue;
                if (chosen.count(x)) {
                    cout << "GOOD: leaf " << leaf+1 << " died at poison " << x+1 << endl;
                    continue;
                }
                if (leaves.count(x)) {
                    cout << "BAD: leaf " << leaf+1 << " can reach leaf " << x+1 << endl;
                    exit(0);
                }
                bfs.push(x);
                visited[x] = true;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        int val; cin >> val;

        vector<vector<int>> tree(val);
        vector<vector<int>> graph(val);

        // vector<int> notConnected;
        // for (int i = 1; i < val; i++)
        //     notConnected.push_back(i);
        // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        // shuffle(begin(notConnected), end(notConnected), std::default_random_engine(seed));
        // notConnected.push_back(0);

        // vector<int> parents(val);
        // while(!notConnected.empty()) {
        //     int parent = notConnected.back();
        //     notConnected.pop_back();

        //     int num;
        //     if ((int)notConnected.size() == 1) num = 1;
        //     else {
        //         do {
        //             num = rand() % (int)notConnected.size();
        //         } while (num == (int)notConnected.size() - 1);
        //     }
            
        //     for (int i = 0; i < num; i++) {
        //         int child = notConnected.back();
        //         notConnected.pop_back();
        //         tree[parent].push_back(child);
        //         graph[parent].push_back(child);
        //         graph[child].push_back(parent);
        //         parents[child] = parent;
        //     }
            
        // }
        // for (int i : parents) cout << i+1 << ' ';
        // cout << endl;

        for (int i = 1; i < val; i++) {
            int par; cin >> par;
            par--;
            tree[par].push_back(i);
            graph[par].push_back(i);
            graph[i].push_back(par);
        }

        chosen.clear();
        solve(tree);
        check(graph);

        // for (int i = 0; i < val; i++) {
        //     cout << i+1 << ':' << endl;
        //     for (int c : tree[i]) cout << c+1 << ' ';
        //     cout << endl;
        //     for (int c : graph[i]) cout << c+1 << ' ';
        //     cout << endl << endl;
        // }

        cout << "Poisoned nodes: ";
        for (int i : chosen) cout << i+1 << ' ';
        cout << endl;
    }
    return 0;
}