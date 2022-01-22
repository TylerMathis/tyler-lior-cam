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

    int n; cin >> n;
    vector<string> sen(n);
    for (auto &x : sen) cin >> x;
    int m; cin >> m;

    map<string, vector<string>> correct, incorrect;
    for (int i = 0; i < m; i++) {
        string word, trans, status;
        cin >> word >> trans >> status;
        if (status == "correct") correct[word].push_back(trans);
        else incorrect[word].push_back(trans);
    }

    ll totalOptions = 1, correctOptions = 1;
    for (string s : sen) {
        ll numCorrect = sz(correct[s]);
        ll numIncorrect = sz(incorrect[s]);
        totalOptions *= (numCorrect + numIncorrect);
        correctOptions *= numCorrect;
    }

    if (totalOptions == 1) {
        bool isCorrect = true;
        for (string s : sen) {
            if (sz(correct[s])) cout << correct[s][0] << ' ';
            else {
                isCorrect = false;
                cout << incorrect[s][0] << ' ';
            }
        }
        cout << nl;
        cout << (isCorrect ? "correct" : "incorrect") << nl;
    } else {
        cout << correctOptions << " correct" << nl;
        cout << (totalOptions - correctOptions) << " incorrect" << nl;
    }

    return 0;
}
