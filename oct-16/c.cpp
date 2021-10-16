#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, vi> red, green, blue;
map<int, bool> stillExists;
map<int, vector<int>> dependencies;

struct card {
    int r, g, b, id;
    card(int r, int g, int b, int id) :
    r(r), g(g), b(b), id(id) {}
    card() {}
    int calcUniqueness() {
        // r
        int start = r;
        
        int redClosestUp, redClosestUpAngle;
        for (int iter = start; iter <= iter + 360; iter++) {
            int angle = iter % 360;
            
            bool found = false;
            for (int id : red[angle])
                if (stillExists[id]) {
                    redClosestUp = id;
                    redClosestUpAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        int redClosestDown, redClosestDownAngle;
        for (int iter = start; iter >= iter - 360; iter--) {
            int angle = iter < 0 ? iter + 360 : iter;
            
            bool found = false;
            for (int id : red[angle])
                if (stillExists[id]) {
                    redClosestDown = id;
                    redClosestDownAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        int greenClosestUp, greenClosestUpAngle;
        for (int iter = start; iter <= iter + 360; iter++) {
            int angle = iter % 360;
            
            bool found = false;
            for (int id : green[angle])
                if (stillExists[id]) {
                    greenClosestUp = id;
                    greenClosestUpAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        int greenClosestDown, greenClosestDownAngle;
        for (int iter = start; iter >= iter - 360; iter--) {
            int angle = iter < 0 ? iter + 360 : iter;
            
            bool found = false;
            for (int id : green[angle])
                if (stillExists[id]) {
                    greenClosestDown = id;
                    greenClosestDownAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        int blueClosestUp, blueClosestUpAngle;
        for (int iter = start; iter <= iter + 360; iter++) {
            int angle = iter % 360;
            
            bool found = false;
            for (int id : blue[angle])
                if (stillExists[id]) {
                    blueClosestUp = id;
                    blueClosestUpAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        int blueClosestDown, blueClosestDownAngle;
        for (int iter = start; iter >= iter - 360; iter--) {
            int angle = iter < 0 ? iter + 360 : iter;
            
            bool found = false;
            for (int id : blue[angle])
                if (stillExists[id]) {
                    blueClosestDown = id;
                    blueClosestDownAngle = angle;
                    found = true;
                    break;
                }
            if (found) break;
        }

        dependencies[redClosestDown].push_back(id);
        dependencies[redClosestUp].push_back(id);
        dependencies[greenClosestDown].push_back(id);
        dependencies[greenClosestUp].push_back(id);
        dependencies[blueClosestDown].push_back(id);
        dependencies[blueClosestUp].push_back(id);

        int redAngle = min(360 - abs(redClosestDownAngle - redClosestUpAngle), abs(redClosestDownAngle - redClosestUpAngle));
        int greenAngle = min(360 - abs(greenClosestDownAngle - greenClosestUpAngle), abs(greenClosestDownAngle - greenClosestUpAngle));
        int blueAngle= min(360 - abs(blueClosestDownAngle - blueClosestUpAngle), abs(blueClosestDownAngle - blueClosestUpAngle));
    
        int sum = redAngle + greenAngle + blueAngle;
        return sum;
    }
};

map<int, card> cards;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    fill(all(stillExists), true);

    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        int r, g, b, id; cin >> r >> g >> b >> id;
        ids[i] = id;
        red[r].push_back(id);
        green[g].push_back(id);
        blue[b].push_back(id);
        cards[id] = card(r, g, b, id);
    }

    vector<pii> sortedIds;
    for (int i = 0; i < n; i++) {
        sortedIds.emplace_back(cards[ids[i]].calcUniqueness(), ids[i]);
    }
    sort(all(sortedIds));

    // keep removing
    for (int i = 0; i < n - 1; i++) {
        int lowest = sortedIds[i].second;
        cout << lowest << endl;
        stillExists[lowest] = false;
        sortedIds.erase(sortedIds.begin() + i);
        for (int id : dependencies[lowest]) {
            cards[id].calcUniqueness();
        }
    }

    return 0;
}
