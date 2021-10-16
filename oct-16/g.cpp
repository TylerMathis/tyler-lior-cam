#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TI>
using indexed_set = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key
// find_by_order

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> teams(n); // t idx

	indexed_set<vector<int>> order;
	for (int i = 0; i < n; i++) {
		teams[i].first = n;
		order.insert({teams[i].first, teams[i].second, i});
	}

	for (int i = 0; i < m; i++) {
		int t, p;
		cin >> t >> p;
		t--;

		vector<int> team = {teams[t].first, teams[t].second, t};

		auto it = order.find(team);
		assert(it != order.end());

		vector<int> curr = *it;
		order.erase(it);

		teams[t].first--;
		teams[t].second += p;

		order.insert({teams[t].first, teams[t].second, t});

		cout << 1 + order.order_of_key({teams[0].first, teams[0].second, 0}) << '\n';
	}

	return 0;
}
