#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
vector<bool> primes;

void solve() {
	double a, b;
	cin >> a >> b;

	double div = b / a;

	for (int i = 2; i < 110; i++) {
		if (primes[i]) {
			double other = double(i) * div;

			auto test = [&](double eps, double add) {
				if (eps < 1e-9) {
					int curr = int(other + add);

					assert(curr < MAX);

					if (primes[curr]) {
						cout << i << ' ' << curr << endl;
						return true;
					}
				}
				return false;
			};

			double eps = abs(other - int(other));
			double oeps = abs(int(other + 0.5) - other);
			if (test(eps, 0))
				return;
			if (test(oeps, 0.5))
				return;
		}
	}

	cout << "impossible" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	primes = vector<bool>(MAX, 1);
	primes[0] = primes[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (primes[i]) {
			for (int j = i + i; j < MAX; j += i) {
				primes[j] = 0;
			}
		}
	}

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
