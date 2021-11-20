#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<unordered_set<int>> adj(5);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b, a--, b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	for (int mask = 0; mask < (1 << 5); mask++) {
		vector<int> d;
		for (int bit = 0; bit < 5; bit++)
			if (mask & (1 << bit))
				d.push_back(bit);

		if (size(d) == 3) {
			if ((adj[d[0]].count(d[1]) && adj[d[0]].count(d[2]) &&
						adj[d[1]].count(d[0]) && adj[d[1]].count(d[2]) &&
						adj[d[2]].count(d[0]) && adj[d[2]].count(d[1])) ||
					!(adj[d[0]].count(d[1]) || adj[d[0]].count(d[2]) ||
						adj[d[1]].count(d[0]) || adj[d[1]].count(d[2]) ||
						adj[d[2]].count(d[0]) || adj[d[2]].count(d[1]))) {
				cout << "Happy Doggos!\n";
				exit(0);
			}
		}
	}

	cout << "Sad Doggos...\n";

	return 0;
}
