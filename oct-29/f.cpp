#include <bits/stdc++.h>
using namespace std;

int LSIS(vector<int> &arr) {//longest strictly increasing sequence
	multiset<int> seq;
	for(int i = 0; i < (int)arr.size(); ++i) {
		seq.insert(arr[i]);
		auto it = seq.lower_bound(arr[i]);
		it++;
		if(it != seq.end()) seq.erase(it);
	}
	return seq.size();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<int> a(n), b(n);

	for (auto & x : a) cin >> x;
	for (auto & x : b) cin >> x;

	map<int, int> idxOfBInA;
	for (int i = 0 ; i < n; i++) {
		idxOfBInA[a[i]] = i;
	}

	vector<int> c(n);
	for (int i = 0; i < n; i++)
		c[i] = idxOfBInA[b[i]];

	cout << LSIS(c) << endl;

	return 0;
}

