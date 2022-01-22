#include <bits/stdc++.h>
#include "testlib.h"

#define long long long int

using namespace std;

vector<int> w, l, r, s;
vector<bool> z;

void dfs(int x) {
    if (z[x]) quitf(_wa, "not a tree");
    z[x] = true;
    int sl = 0;
    int sr = 0;
    if (l[x] != -1) {
        dfs(l[x]);
        sl = s[l[x]];
    }
    if (r[x] != -1) {
        dfs(r[x]);
        sr = s[r[x]];
    }
    if (abs(sl - sr) > 1) {
        quitf(_wa, "not almost balanced");
    }
    s[x] = w[x] + sl + sr;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int a = inf.readInt();
    int b = inf.readInt();

    int pa = ouf.readInt();
    if (pa == -1) {
        int ja = ans.readInt();
        if (ja == -1) {
// GAM            quitf(_ok, "impossible");
           quitf(_ok, "");
        } else {
            quitf(_wa, "not impossible");
        }
    }
    ouf.reset();

    int n = a + b;
    w.resize(n);
    l.resize(n);
    r.resize(n);
    for (int i = 0; i < n; i++) {
        w[i] = ouf.readInt(1, 2);
        l[i] = ouf.readInt(0, n) - 1;
        r[i] = ouf.readInt(0, n) - 1;
    }
    z.resize(n);
    s.resize(n);
    dfs(0);

    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        if (!z[i]) quitf(_wa, "not a tree");
        cnt[w[i]]++;
    }
    if (cnt[1] != a || cnt[2] != b) {
        quitf(_wa, "wrong number of nodes");
    }
    quitf(_ok, "");
}
