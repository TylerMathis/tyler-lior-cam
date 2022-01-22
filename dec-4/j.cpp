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

    string inp; cin >> inp;
    vi in; for (char c : inp) in.push_back(c - '0');

    while (true) {
        vi buf = in;
        for (int i = 0; i < sz(in); i++) {
            if (in[i] >= 2) {
                if (i) buf[i-1]++;
                if (i < sz(in) - 1) buf[i+1]++;
                buf[i] -= 2;
            }
        }

        in = buf;
        bool good = true;
        for (int c : in) {
            if (c > 1) {
                good = false;
                break;
            }
        }

        if (good) {
            for (int c : in)
                cout << c;
            cout << endl;
            return 0;
        }
    }

    return 0;
}

