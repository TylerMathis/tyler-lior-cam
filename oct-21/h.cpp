#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(9);

    vector<double> prefixPetalCount;
    vi petals;
    prefixPetalCount.push_back(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char q; cin >> q;
        double val; cin >> val;
        if (q == 'R') {
            prefixPetalCount.push_back(prefixPetalCount.back() + val);
            petals.push_back(val);
        } else {
            double stdDev = 0;
            double average = prefixPetalCount.back() / sz(petals);
            for (int p : petals)
                stdDev += (p - average) * (p - average);
            stdDev = sqrt(stdDev / sz(petals));

            double sampleStdDev = stdDev / sqrt(val);

            double petalsBackwards = prefixPetalCount.back() - prefixPetalCount[sz(prefixPetalCount) - val - 1];
            double sampleAverage = petalsBackwards / val;

            double lo = average - 2 * sampleStdDev;
            double hi = average + 2 * sampleStdDev;

            cout << lo << ' ' << hi << endl;
        }
    }

    return 0;
}
