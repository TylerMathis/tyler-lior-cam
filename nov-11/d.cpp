#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point {
	double x, y, z;
	double dist() const {
		return sqrt(x*x + y*y + z*z);
	}
	bool operator<(const point &o) const {
		return dist() < o.dist();
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
	cout << fixed << setprecision(8);

	int n, k; cin >> n >> k;
	vector<point> points(n);
	for (auto &[x, y, z] : points)
		cin >> x >> y >> z;

	sort(all(points));
	cout << points[k-1].dist() << endl;

    return 0;
}
