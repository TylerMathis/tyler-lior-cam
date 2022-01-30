#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define nl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void error() {
    cout << "RUN-TIME ERROR";
    exit(0);
}

bool isNumeric(string s) {
    int idx = 0;
    if (s[0] == '-') idx++;
    for (idx; idx < sz(s); idx++)
        if (s[idx] < '0' || s[idx] > '9')
            return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string prog; cin >> prog;

    stack<int> stck;
    map<int, int> heap;
    map<string, int> jumps;

    auto checkStackFull = [&stck]() {
        if (sz(stck) >= 1024)
            error();
    };
    
    auto checkStackEmpty = [&stck]() {
        if (sz(stck) == 0)
            error();
    };

    auto getTwo = [&stck, &checkStackEmpty]() {
        checkStackEmpty();
        auto one = stck.top();
        stck.pop();
        checkStackEmpty();
        auto two = stck.top();
        return make_pair(one, two);
    };

    auto getOne = [&stck, &checkStackEmpty]() {
        checkStackEmpty();
        auto top = stck.top();
        stck.pop();
        return top;
    };

    auto go = [&](int progIdx, auto &&go) {
        while (progIdx < sz(prog)) {
            if (progIdx <= sz(prog) - 3) {
                string three = prog.substr(progIdx, 3);

                if (three == "000" || three == "001") {
                    string arg;
                    if (!(cin >> arg)) error();
                    if (!isNumeric(arg)) error();
                    int val = stoi(arg);
                    checkStackFull();
                    stck.push(val);
                }
                else if (three == "020") {
                    checkStackEmpty();
                    checkStackFull();
                    stck.push(stck.top());
                }
                else if (three == "021") {
                    auto top = getTwo();
                    stck.push(top.first);
                    stck.push(top.second);
                }
                else if (three == "022") {
                    checkStackEmpty();
                    stck.pop();
                }
                else if (three == "110") {
                    auto [s1, s2] = getTwo();
                    heap[s2] = s1;
                }
                else if (three == "111") {
                    auto top = getOne();
                    stck.push(heap[top]);
                }
                else if (three == "200") {
                    string arg;
                    if (!(cin >> arg)) error();
                    jumps[arg] = progIdx + 3;
                }
                else if (three == "201") {
                    string arg;
                    if (!(cin >> arg)) error();
                    go(jumps[arg], go);
                }
                else if (three == "202") {
                    string arg;
                    if (!(cin >> arg)) error();
                    progIdx = jumps[arg];
                }
                else if (three == "210") {
                    string arg;
                    if (!(cin >> arg)) error();
                    auto top = getOne();
                    if (top == 0) {}
                }
            }
        }
    };

    return 0;
}

