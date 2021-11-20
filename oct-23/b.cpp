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

    int n, width, height; cin >> n >> width >> height;

    vector<pii> books(n);
    for (auto &[x, y]: books) cin >> x >> y;
    sort(all(books));
    reverse(all(books));

    bool won = false;
    for (int i = 0; i <= height/2; i++) {
        // test it

        int topFilled = 0, botFilled = 0;
        int botHeight = i;
        int topHeight = height - i;

        bool valid = true;
        for (pii b : books) {
            int bh = b.second;
            int bw = b.first;

            if (bh <= botHeight) {
                if (width - botFilled >= bw) {
                    botFilled += bw;
                } else if (width - topFilled >= bw) {
                    topFilled += bw;
                } else {
                    valid = false;
                    break;
                }
            } else if(bh <= topHeight){
                if (width - topFilled >= bw) {
                    topFilled += bw;
                } else {
                    valid = false;
                    break;
                }
            }else{
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << (i == 0 ? -1 : i) << endl;
            won = true;
            break;
        }
    }

    if (!won) {
        cout << "impossible" << endl;
    }

    return 0;
}
