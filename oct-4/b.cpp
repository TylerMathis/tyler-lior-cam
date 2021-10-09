#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "brothers"

int m, n;
int pairs;

const int LIM = 1e9;
unordered_set<int> ps;
void eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM / 2;
    vi sieve(S+1);
    vector<pii> cp;
    for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
        cp.push_back({i, i * i / 2});
        for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
    }
    for (int L = 1; L <= R; L += S) {
        array<bool, S> block{};
        for (auto &[p, idx]: cp)
            for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;
        rep(i, 0, min(S, R - L))
            if (!block[i]) {
                int pri = (L + i) * 2 + 1;
                if (pri >= m && pri <= n) {
                    ps.insert(pri);
                    if (ps.count(pri - 2010)) {
                        ps.erase(pri - 2010);
                        pairs++;
                    }
                }
            }
    }   
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin);
    // freopen(filename ".out", "w", stdout);

    cin >> m >> n;
    pairs = 0;
    eratosthenes();
    cout << pairs << endl;

    return 0;
}
