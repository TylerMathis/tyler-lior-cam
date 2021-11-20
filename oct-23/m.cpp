#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
			cout << 1;
		cout << ' ';
	}
	return 0;
}
