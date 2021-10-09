#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define filename "express"

int n;
ll mod;
ll dp[1'000'000][3][2];

ll go(int idx, int taken, int start) {
    if (idx >= n) return 0;
    
    auto &ans = dp[idx][taken][start];
    if (ans != -1) return ans;

    ll cnt = 0;

    if (taken >= 1 && !(idx == n - 1 && start == 1)) {
        cnt += (1 + go(idx + 2, 2, start)) % mod;
        cnt %= mod;
    } else {
        cnt += (go(idx + 2, 1, idx == 0 ? 1 : 0)) % mod;
        cnt %= mod;
    }
    cnt += go(idx + 1, taken, start) % mod;
    cnt %= mod;

    return ans = cnt;
}

long long binpow(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

ll cams(int n) {}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(filename ".in", "r", stdin), freopen(filename ".out", "w", stdout);

    cin >> n >> mod;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
    cout << go(0, 0, 0) << endl;

    return 0;
}
