#include <bits/stdc++.h>
using namespace std;

int root;

bool beautiful(vector<vector<int>> & tree, int u, int p, int c, bool hit) {
	if (!(c & (1 << root)))
		return 0;
	if (((1 << u) & c) != ((1 << p) & c)) {
		if (!hit)
			hit = 1;
		else
			return 0;
	}
	bool is = 1;
	for (auto & v : tree[u])
		if (v != p)
			is &= beautiful(tree, v, u, c, hit);
	return is;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	for (int i = 0; i < n - 1; i++) {
		int p;
		cin >> p, p--;
		if (p == i)
			root = i;
		else {
			tree[p].push_back(i);
			tree[i].push_back(p);
		}
	}
	vector<int> dp(1 << n), t(1 << n, -1);
	for (int c = 0; c < (1 << n); c++) {
		if (beautiful(tree, root, root, c, 0)) {
			for (int u = 0; u < n; u++) {
				if ((c & (1 << u))) {
					for (int v = 0; v < n; v++) {
						if (!(c & (1 << v))) {
							if (dp[c] < dp[c ^ (1 << v) ^ (1 << u)] + 2) {
								dp[c] = dp[c ^ (1 << v) ^ (1 << u)] + 2;
								t[c] = c ^ (1 << v) ^ (1 << u);
							}
						}
					}
				}
			}
		}
	}
	cout << *max_element(begin(dp), end(dp)) << '\n';
	return 0;
}
