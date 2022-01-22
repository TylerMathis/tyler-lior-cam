#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = size(s);
		string smallest = s;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				reverse(begin(s) + i, begin(s) + j + 1);
				if (s < smallest)
					smallest = s;
				reverse(begin(s) + i, begin(s) + j + 1);
			}
		}
		cout << smallest << '\n';
	}

	return 0;
}
