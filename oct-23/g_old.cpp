#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct disjointSet {
	int numberOfSets;
	vector<int> parent;
	disjointSet() { }
	disjointSet(int n) : numberOfSets(n), parent(n, -1) { }
	int find(int x) {return parent[x] < 0 ? x : parent[x] = find(parent[x]);}
	int sizeOfSet(int x) {return -parent[find(x)];}
	bool merge(int x, int y) {
		if ((x=find(x)) == (y=find(y))) return 0;
		if (parent[y] < parent[x]) swap(x, y);
		parent[x] += parent[y];
		parent[y] = x;
		numberOfSets--;
		return 1;
	}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int h, w, k; cin >> h >> w >> k;

    vi filled(w, 0);
    map<int, int> aCols, aRows, aUpRight, aDownRight;
    map<int, int> bCols, bRows, bUpRight, bDownRight;

    int turn = 0;
    bool found = false;
    for (int i = 0; i < h*w; i++) {
        int loc; cin >> loc;
        int row = loc;
        int col = filled[row];
        filled[row]++;

        int mx = 0;
        
        

        turn++;
    }

    if (!found) cout << "D" << endl;

    return 0;
}
