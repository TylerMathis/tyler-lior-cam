#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T dist2() const { return x*x + y*y; }
    T dist() const { return sqrt((double)dist2()); }
};

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    assert(d != 0);
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    return {1, (s1 * p + e1 * q) / d};
}

template<class P>
P proj(P ls, P le, P p) {
    P v1 = le - ls;
    double k = v1.dot(p - ls) / v1.dist2();
    return v1 * k + ls;
}

template<class P>
P reflect(P p, P ap) {
    return ap + (p - ap) * 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(4);

    typedef Point<double> pd;

    double bx, cx, cy; cin >> bx >> cx >> cy;
    pd A, B, C;
    A = pd(0., 0.);
    B = pd(bx, 0.);
    C = pd(cx, cy);

    pd midAB, midBC, midCA;
    midAB = pd((B.x + A.x) / 2, (B.y + A.y) / 2);
    midBC = pd((C.x + B.x) / 2, (C.y + B.y) / 2);
    midCA = pd((A.x + C.x) / 2, (A.y + C.y) / 2);

    // TODO CAN BE INF
    bool infSlopeBC = C.x == B.x;
    bool infSlopeCA = A.x == C.x;
    
    bool infSlopeBCinv = C.y == B.y;
    bool infSlopeCAinv = A.y == C.y;

    double slopeBCinv = (infSlopeBCinv) ? 0. : -1.0 / ((C.y - B.y) / (C.x - B.x));
    double slopeCAinv = (infSlopeCAinv) ? 0. : -1.0 / ((A.y - C.y) / (A.x - C.x));

    if (infSlopeBC) slopeBCinv = 0;
    if (infSlopeCA) slopeCAinv = 0;

    pd perpAB2 = midAB + pd(0., 1.);
    pd perpBC2 = midBC + (infSlopeBCinv ? pd(0., 1.) : pd(1., slopeBCinv));
    pd perpCA2 = midCA + (infSlopeCAinv ? pd(0., 1.) : pd(1., slopeCAinv));

    pair<pd, pd>
        perpAB(midAB, perpAB2),
        perpBC(midBC, perpBC2),
        perpCA(midCA, perpCA2);

    pair<pd, pd>
        ha(pd(0., 0.), (infSlopeBCinv ? pd(0., 1.) : pd(1, slopeBCinv))),
        hb(pd(bx, 0.), (infSlopeCAinv ? pd(bx, 1.) : pd(bx + 1, slopeCAinv))),
        hc(pd(cx, cy), pd(cx, cy - 1));

    Point<double> ap = lineInter(perpCA.first, perpCA.second, hc.first, hc.second).second;
    Point<double> bp = lineInter(perpAB.first, perpAB.second, ha.first, ha.second).second;
    Point<double> cp = lineInter(perpBC.first, perpBC.second, hb.first, hb.second).second;

    // cout << hb.first.x << ' ' << hb.first.y << ' ' << hb.second.x << ' ' << hb.second.y << endl;
    // cout << perpBC.first.x << ' ' << perpBC.first.y << ' ' << perpBC.second.x << ' ' << perpBC.second.y << endl;

    // cout << cp.x << ' ' << cp.y << endl;

    // cout << bp.x << ' ' << bp.y << endl;
    // cout << cp.x << ' ' << cp.y << endl;

    double a = (bp - ap).dist();
    double b = (cp - bp).dist();
    double c = (ap - cp).dist();

    double s = (a + b + c) / 2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));

    pd apProj = proj(C, A, ap);
    pd bpProj = proj(A, B, bp);
    pd cpProj = proj(B, C, cp);

    // cout << apProj.x << ' ' << apProj.y << endl;
    // cout << bpProj.x << ' ' << bpProj.y << endl;
    // cout << cpProj.x << ' ' << cpProj.y << endl;

    pd app = reflect(apProj, ap);
    pd bpp = reflect(bpProj, bp);
    pd cpp = reflect(cpProj, cp);

    // cout << app.x << ' ' << app.y << endl;
    // cout << bpp.x << ' ' << bpp.y << endl;
    // cout << cpp.x << ' ' << cpp.y << endl;

    double a2 = (bpp - app).dist();
    double b2 = (cpp - bpp).dist();
    double c2 = (app - cpp).dist();

    double s2 = (a2 + b2 + c2) / 2;
    double area2 = sqrt(s2*(s2-a2)*(s2-b2)*(s2-c2));

    double firstArea = (bx * cy) / 2;

    cout << firstArea << ' ' << area << ' ' << area2 << endl;

    return 0;
}
