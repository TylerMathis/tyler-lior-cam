#include <bits/stdc++.h>
using namespace std;

int cnt;
int bigProd;
void brute(int idx, int lastVal, int mx, int len, int prod) {
    if (idx >= len) {
        cnt++;
        cout << prod << endl;
        bigProd += prod;
        return;
    }
    for (int i = lastVal; i <= mx; i++) {
        brute(idx + 1, i, mx, len, prod * i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const int start = 3;
    for (int i = start; i < 10; i++) {
        cnt = 0; bigProd = 0;
        cout << start << ' ' << i << endl;
        brute(0, 1, i, start, 1);
        cout << bigProd << '/' << cnt << endl << endl;
    }

    return 0;
}