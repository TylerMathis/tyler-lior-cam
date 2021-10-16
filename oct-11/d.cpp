#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<string> t(n);
	for (auto & s : t)
		cin >> s;

	//vector<vector<int>> r(n, vector<int>(m)), d(n, vector<int>(m));

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			r[i][j] = r[i][max(j - 1, 0ll)] + t[i][j] == '*';
			d[i][j] = d[max(i - 1, 0ll)][j] + t[i][j] == '*';
		}
	}
	*/

	/*
	// r
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << r[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';

	// d
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << d[i][j] << ' ';
		cout << '\n';
	}

	cout << '\n';
	*/

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (t[i][j] == '*') {
				/*
				int _n = d[i][j] - 1;
				int _s = d[n - 1][j] - d[i][j];
				int _e = r[i][j] - 1;
				int _w = r[i][m - 1] - r[i][j];
				sum += (_n * _e) + (_n * _w) + (_s * _e) + (_s * _w);
				*/
				int _n = 0;
				int _s = 0;
				int _e = 0;
				int _w = 0;

				for (int k = 0; k < i; k++)
					_n += t[k][j] == '*';

				for (int k = i + 1; k < n; k++)
					_s += t[k][j] == '*';

				for (int k = 0; k < j; k++)
					_w += t[i][k] == '*';

				for (int k = j + 1; k < m; k++)
					_e += t[i][k] == '*';

				sum += (_n * _e) + (_n * _w) + (_s * _e) + (_s * _w);
			}
		}
	}

	cout << sum << '\n';

	return 0;
}
