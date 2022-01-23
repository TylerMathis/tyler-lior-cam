#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	long long n = rng() % 10000 + 1000;
	cout << n << '\n';

	return 0;
}
