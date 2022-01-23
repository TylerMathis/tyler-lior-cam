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

    int N, M; cin >> N >> M;
    vector<vi> adjList(N);

    int children[N];
    for (int i = 0 ; i < N; i++)
        children[i] = 0;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        children[a]++;
        children[b]++;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    ll chooses[N+1];
    for (int i = 3; i <= N; i++)
        chooses[i] = (i * (i - 1) * (i - 2)) / 6;

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (children[i] < 4) continue;
        ll mult = chooses[children[i] - 1];
        for (int c : adjList[i])
            ans += mult * (children[c] - 1);
    }

    cout << ans << "\n";

    return 0;
}
