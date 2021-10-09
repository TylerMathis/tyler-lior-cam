#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<string> barn;

bool won(pii a) {
    return a.first == n-1 && a.second == n-1;
}

struct cowPos {
    pii a, b;
    int dirA;
    int dirB;
    int dist;
    cowPos(pii a, pii b, int da, int db, int d) :
    a(a), b(b), dirA(da), dirB(db), dist(d) {}
    void turnRight() {
        dirA--;
        dirB--;
        if (dirA == -1) dirA = 3;
        if (dirB == -1) dirB = 3;
        dist++;
    }
    void turnLeft() {
        dirA++;
        dirB++;
        if (dirA == 4) dirA = 0;
        if (dirB == 4) dirB = 0;
        dist++;
    }
    void moveForwards() {

        if (!won(a) &&
            a.first + dx[dirA] >= 0 &&
            a.first + dx[dirA] < n &&
            a.second + dy[dirA] >= 0 &&
            a.second + dy[dirA] < n &&
            barn[a.first + dx[dirA]][a.second + dy[dirA]] != 'H') {

            a.first += dx[dirA];
            a.second += dy[dirA];
        }

        if (!won(b) &&
            b.first + dx[dirB] >= 0 &&
            b.first + dx[dirB] < n &&
            b.second + dy[dirB] >= 0 &&
            b.second + dy[dirB] < n &&
            barn[b.first + dx[dirB]][b.second + dy[dirB]] != 'H') {
            
            b.first += dx[dirB];
            b.second += dy[dirB];
        }

        dist++;
    }
    bool win() {
        return won(a) && won(b);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> n;
    barn = vector<string>(n);
    for (auto &x : barn) cin >> x;
    reverse(all(barn));

    queue<cowPos> bfs;
    bool visited[20][20][20][20][4] = {0};
    cowPos start({0, 0}, {0, 0}, 1, 0, 0);
    bfs.push(start);
    visited[0][0][0][0][1] = true;

    while (!bfs.empty()) {
        auto cur = bfs.front();
        bfs.pop();

        // for each possible move
        // if it is not bad for both cows then take it
        
        vector<cowPos> moves;

        // turn left
        cowPos left = cur;
        left.turnLeft();
        //left.moveForwards();
        moves.push_back(left);

        // turn right 
        cowPos right = cur;
        right.turnRight();
        //right.moveForwards();
        moves.push_back(right);

        // move forwards
        cowPos move = cur;
        move.moveForwards();
        moves.push_back(move);

        for (cowPos m : moves) {
            // cout << m.a.first << ' ' << m.a.second << ' ' << m.b.first << ' ' << m.b.second << ' ' << m.dist << endl;
            // cout << visited[m.a.first][m.a.second][m.b.first][m.b.second][m.dirA] << endl;
            // cout << barn[m.a.first][m.a.second] << endl;
            if (!visited[m.a.first][m.a.second][m.b.first][m.b.second][m.dirA]) {
                visited[m.a.first][m.a.second][m.b.first][m.b.second][m.dirA] = true;
                if (m.win()) {
                    cout << m.dist << endl;
                    return 0;
                }
                bfs.push(m);
            }
        }
        
    }

    return 0;
}
