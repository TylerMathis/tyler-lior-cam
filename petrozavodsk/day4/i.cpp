#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int N = 1e6 + 1;
int twos[N];

template<typename Is, typename T> Is & operator >> (Is & is, vector<T> & v) {
    for (auto & x : v)
	is >> x;
    return is;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    twos[0] = 1;
    for (int i = 1; i < N; i++)
	(twos[i] = twos[i - 1] + twos[i - 1]) %= MOD;

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;

    unordered_map<int, int> comp;
    comp.reserve(n + n);
    auto compress = [&](auto & v) {
	for (auto & x : v) {
	    if (!comp.count(x))
		comp[x] = size(comp);
	    x = comp[x];
	}
    };

    compress(a), compress(b);

    unordered_map<int, int> negInter; // a = +, b = -
    negInter.reserve(n);

    unordered_map<int, int> suffHashes;
    suffHashes.reserve(n);

    int currHash = 0;
    int suffHash = 0;

    auto add = [&](int x) {
	negInter[x]++;
	if (negInter[x] == 0)
	    negInter.erase(x);
	(currHash += twos[x]) %= MOD;
	(suffHash -= twos[x]) %= MOD;
    };

    auto sub = [&](int x) {
	negInter[x]--;
	if (negInter[x] == 0)
	    negInter.erase(x);
	(currHash -= twos[x]) %= MOD;
	(suffHash += twos[x]) %= MOD;
    };

    for (int i = n - 1; i >= 1; i--) {
	add(a[i]);
	sub(b[i]);

	suffHashes[currHash]++;
    }

    // reset for the prefix
    negInter.clear();
    suffHash = currHash;
    currHash = 0;

    int ways = 0;

    for (int i = 1; i < n; i++) {
	sub(a[i]);
	add(b[i]);

	suffHashes[suffHash]--;
	if (suffHashes[suffHash] == 0)
	    suffHashes.erase(suffHash);

	int splits = suffHashes[currHash];

	// add all possible chooses
	(ways += twos[splits]) %= MOD;

	// remove choose 1
	(ways -= splits) %= MOD;

	// remove the empty set
	(ways = ways - 1) %= MOD;
    }

    cout << ways << '\n';

    return 0;
}
