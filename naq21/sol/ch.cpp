#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 6'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 2; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

#define int long long

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	auto pr = eratosthenesSieve(MAX_PR);

	int n;
	cin >> n;
	__int128_t val = 1;
	vector<int> facts;
	for (int i = 0; val * pr[i] <= n && i < (int) size(pr); i++) {
		val *= pr[i];
		facts.push_back(pr[i]);
	}

	int k = size(facts);
	int f = 0;
	int top = k;
	int bot = 1;
	for (int i = 0; i < k; i++) {
		int x = i + 1;
		f += top / bot;
		top *= k - x;
		bot *= x;
	}
	f += top / bot;

	cout << f << endl;
	int gcd = __gcd(f, (long long)val);
	cout << (f / gcd) << '/' << ((long long)val / gcd) << '\n';

	return 0;
}
