#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	cout << 1 << '\n';
	int n = rand() % 3 + 4;
	for (int i = 0; i < n; i++)
		cout << char('a' + (rng() % 26));
	cout << '\n';

	return 0;
}
