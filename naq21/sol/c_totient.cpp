#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 500'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	auto pr = eratosthenesSieve(MAX_PR);

	unsigned long long n;
	cin >> n;
	unsigned long long val = 1;
	vi facts;
	for (int i = 0; val * pr[i] <= n && i < sz(pr); i++) {
		val *= pr[i];
		facts.push_back(pr[i]);
	}

        ll totient = val;
        for (ll f : facts)
            totient -= totient / f;

        unsigned long long comp = val - totient;
	ll gcd = __gcd(comp, val);
	cout << (comp / gcd) << '/' << (val / gcd) << '\n';

	return 0;
}
