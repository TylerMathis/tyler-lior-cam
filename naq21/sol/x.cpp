#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	int f = 0;
	for (int i = 2; i <= n; i++)
		if (__gcd(i, n) > 1)
			f++;
	cout << f << '\n';

	return 0;
}
