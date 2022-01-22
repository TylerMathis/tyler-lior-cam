#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double circles[510][510];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        double r; cin >> r;
        circles[x][y] = r; // no circles overlap
    }

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        int cnt = 0;
        if (x1 == x2) { // vert
            for (int j = min(y1, y2); j <= max(y1, y2); j++)
                if (circles[x1][j]) cnt++;
        } else if (y1 == y2) { // hori
            for (int j = min(x1, x2); j <= max(x1, x2); j++)
                if (circles[j][y1]) cnt++;
        } else {
            // y - y1 = m(x - x1)
            // y = m(x - x1) + y1
            // (y - y1) / m = x - x1
            // x = (y - y1) / m + x1

            pii beg = make_pair(x1, y1);
            pii end = make_pair(x2, y2);
            if (end < beg) swap(beg, end);
            x1 = beg.first; y1 = beg.second;
            x2 = end.first; y2 = end.second;

            double m = (double)(y2 - y1) / (double)(x2 - x1);
            auto y = [&](double x) -> double {
                return m * (x - x1) + y1;
            };
            auto x = [&](double y) -> double {
                return (y - y1) / m + x1;
            };

            set<pii> found;
            for (int x = min(x1, x2); x <= max(x1, x2); x++) {
                double ly = y(x);
                int lo = max(1, (int)floor(ly));
                int hi = min(500, (int)ceil(ly));
                double distToLo = abs(ly - lo);
                double distToHi = abs(ly - hi);
                if (circles[x][lo] && circles[x][lo] > distToLo) found.emplace(x, lo);
                if (circles[x][hi] && circles[x][hi] > distToHi) found.emplace(x, hi);
            }
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                double lx = x(y);
                int lo = max(1, (int)floor(lx));
                int hi = min(500, (int)ceil(lx));
                double distToLo = abs(lx - lo);
                double distToHi = abs(lx - hi);
                if (circles[lo][y] && circles[lo][y] > distToLo) found.emplace(lo, y);
                if (circles[hi][y] && circles[hi][y] > distToHi) found.emplace(hi, y);
            }

            cnt = sz(found);
        }

        cout << cnt << nl;
    }

    return 0;
}
