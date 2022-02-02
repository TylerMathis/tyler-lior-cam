#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())
typedef long long ll;

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<tuple<int, int, int>> intervals(N);
    vector<int> POI;
    for (auto &[s, e, c] : intervals) {
        cin >> s >> e >> c;
        POI.push_back(s);
        POI.push_back(e);
    }

    sort(all(POI));
    map<int, int> compressed;
    for (int i = 0; i < sz(POI); i++)
        compressed[POI[i]] = i;

    vector<int> intersectAtCompressedPOI(sz(POI));
    for (auto &[s, e, c] : intervals) {
        for (int i = 0; i < sz(intervals); i++) {
            
        }
    }
    
    auto go = [&](int idx, int compSize, auto &&go) -> ll {
        
    };

    return 0;
}