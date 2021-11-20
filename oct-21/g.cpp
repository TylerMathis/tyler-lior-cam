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

    int n; cin >> n;

    set<int> times;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        int time; cin >> time;
        freq[time]++;
        times.emplace(time);
    }

    ll fert; cin >> fert;
    int curTime = *(times.rbegin());
    int numFlowers = 0;
    while (true) {
        if (curTime == 0) break;

        if (freq[curTime])
            numFlowers += freq[curTime];

        if (fert < numFlowers) break;

        fert -= numFlowers;
        curTime--;
    }

    cout << curTime << endl;

    return 0;
}
