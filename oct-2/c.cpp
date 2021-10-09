#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int K = 26;

struct node {
    int next[K];
    bool leaf = 0;
    char pch;
    int p = -1;
    int id;

    node(int p = -1, char ch = '#') : p(p), pch(ch) {
        fill(next, next+K, -1);
    }
};

vector<node> t(1);

void add_string(string s, int id) {
    int c = 0;
    for (char ch: s) {
        int v = ch-'a';
        if (t[c].next[v] == -1) {
            t[c].next[v] = t.size();
            t.emplace_back(c, ch);
        }
        c = t[c].next[v];
    }
    t[c].leaf = 1;
    t[c].id = id;
}

int totalSingle = 0;
int bestCnt = INT_MIN;

int go(int idx, int depth, int cnt) {
    
    if (t[idx].leaf) {
        if (depth == 1) {
            cnt += totalSingle;
        } else {
            cnt++;
        }
        bestCnt = max(bestCnt, cnt);
    } else {
        cnt = 0;
    }
    int most = cnt;
    int best = 0;
    int idxbest = 0;
    for (int i = 0; i < 26; i++) {
        if (t[idx].next[i] != -1) {
            //if we're going to a terminal
            if(t[t[idx].next[i]].leaf)most++;
            int val = go(t[idx].next[i], depth + 1, 0);
            if(val>best){
                best = val;
                idxbest = i;
            }
            best = max(best,val);
        }
    }
    if(t[idxbest].leaf)most--;
    most+=best;
    return most;
}

int teehee(vector<string> s) {
    for (int i = 0; i < sz(s); i++) {
        add_string(s[i], i);
        if (sz(s[i]) == 1) totalSingle++;
    }

    bestCnt = INT_MIN;
    int answer = go(0, 0, 0);
    return answer;
    //return bestCnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<string> str(n);
    for (auto &x : str) cin >> x, reverse(all(x));
    cout << max(-1, teehee(str)) << endl;

    return 0;
}
