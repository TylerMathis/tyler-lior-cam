#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double EPS = 1e-8;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
    if (s == e) return (p-s).dist();
    auto d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
    return ((p - s) * d - (e - s) * t).dist() / d;
}

template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
    int cnt = 0, n = sz(p);
    rep(i,0,n) {
        P q = p[(i + 1) % n];
        if (onSegment(p[i], q, a)) return !strict;
        cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
    }
    return cnt;
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
    T a = v.back().cross(v[0]);
    rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
    return a;
}

vector<P> genUnitPoly(int k) {
    vector<P> polygon;
    double diff = (2 * M_PI) / k;
    for (double theta = 0; theta < 2 * M_PI; theta += diff)
        polygon.emplace_back(cos(theta), sin(theta));
    return polygon;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(9);

    int n; cin >> n;
    vector<P> points;
    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        points.emplace_back(x, y);
    }

    int bestCnt = 0;
    double bestRatio = DBL_MIN;

    for (int k = 3; k <= 8; k++) {
        vector<P> unitPoly = genUnitPoly(k);
        vector<P> actualPoly = unitPoly;

        // outer radius
        double lo = 0, hi = 1e7, m, outerRad = -1;
        while (abs(hi - lo) >= EPS) {
            m = (lo + hi) / 2;
            for (int i = 0; i < sz(actualPoly); i++)
                actualPoly[i] = unitPoly[i] * m;

            bool good = true;
            for (auto &p : points) {
                if (!inPolygon(actualPoly, p)) {
                    good = false;
                    break;
                }
            }

            if (good) hi = m, outerRad = m;
            else lo = m;
        }

        // inner radius
        lo = 0, hi = 1e7;
        double innerRad = -1;
        while (abs(hi - lo) >= EPS) {
            m = (lo + hi) / 2;
            for (int i = 0; i < sz(actualPoly); i++)
                actualPoly[i] = unitPoly[i] * m;

            bool good = true;
            for (auto &p : points) {
                if (inPolygon(actualPoly, p)) {
                    good = false;
                    break;
                }
            }

            if (good) lo = m, innerRad = m;
            else hi = m;
        }

        assert(innerRad != -1);
        assert(outerRad != -1);

        vector<P> outerPoly = unitPoly;
        vector<P> innerPoly = unitPoly;

        for (int i = 0; i < sz(outerPoly); i++)
            outerPoly[i] = unitPoly[i] * outerRad;
        for (int i = 0; i < sz(innerPoly); i++)
            innerPoly[i] = unitPoly[i] * innerRad;

        double ratio = polygonArea2(innerPoly) / polygonArea2(outerPoly);
        if (ratio > bestRatio) {
            bestRatio = ratio;
            bestCnt = k;
        }
    }

    cout << bestCnt << ' ' << bestRatio << nl;

    return 0;
}

