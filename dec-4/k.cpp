#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(9);

    int n; cin >> n;
    vector<double> inp(n);
    for (auto &x : inp) cin >> x;

    int numZerosLeft = 0;
    if (pow(2, (int)log2(n)) == n) {}
    else {
        int newN = pow(2, (int)log2(n) + 1);
        numZerosLeft = newN - n;
        n = newN;
    }

    sort(begin(inp)+1, end(inp));
    vector<double> ratings(n);
    int inpPtr = 0;
    for (int i = 0; i < n; i++) {
        if (i&1 && numZerosLeft > 0) {
            ratings[i] = 0;
            numZerosLeft--;
        } else {
            ratings[i] = inp[inpPtr++];
        }
    }

    vector<vector<double>> probs(n, vector<double>(log2(n)));
    int pw = 1;
    for (int i = 0; i < log2(n); i++) {
        pw *= 2;
        for (int j = 0; j < n; j++) {
            int base = (j / pw) * pw;
            int halfWidth = pw / 2;

            int lo, hi;
            if (j < base + halfWidth) {
                lo = base + halfWidth;
                hi = base + 2*halfWidth;
            } else {
                lo = base;
                hi = base + halfWidth;
            }

            double runningProb = 0;
            for (int k = lo; k < hi; k++) {
                if (ratings[j] == 0 && ratings[k] == 0) continue;
                runningProb += (i != 0 ? probs[k][i-1] : 1.0) * (ratings[j] / (ratings[j] + ratings[k]));
            }

            probs[j][i] = runningProb * (i != 0 ? probs[j][i-1] : 1.0);
        }
    }

    cout << probs[0][log2(n)-1] << nl;

    return 0;
}

