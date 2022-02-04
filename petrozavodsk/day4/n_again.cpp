#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long n, k; cin >> n >> k;
    vector<string> names;
    map<string, long long> curStats;
    map<string, long long> categoryMax;
    map<string, long long> categoryFreq;
    map<string, vector<long long>> categoryEvents;
    long long maxFreq = 0;
    for (int i = 0; i < n; i++) {
        string name;
        int stat;
        cin >> name >> stat;
        names.push_back(name);
        curStats[name] = stat;
    }

    int nn; cin >> nn;
    for (int i = 0; i < nn; i++) {
        string name;
        long long stat;
        cin >> name >> stat;
        categoryMax[name] = max(categoryMax[name], stat);
        categoryFreq[name]++;
        maxFreq = max(maxFreq, categoryFreq[name]);
        categoryEvents[name].push_back(stat);
    }

    // Put us at the thresh
    for (int i = 0; i < n; i++) {
        k -= max(0ll, categoryMax[names[i]] - curStats[names[i]]);
        curStats[names[i]] = max(categoryMax[names[i]], curStats[names[i]]);
        if (k < 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    // Now try our +1 bumps
    priority_queue<pair<pair<long long, long long>, string>> benefits;
    for (int i = 0; i < n; i++) {
        if (curStats[names[i]] == categoryMax[names[i]]) {
            long long actuallyBetter = 0;
            for (long long e : categoryEvents[names[i]])
                if (e == categoryMax[names[i]])
                    actuallyBetter++;
            benefits.emplace(make_pair(
                (categoryMax[names[i]]) * actuallyBetter + categoryFreq[names[i]],
                (categoryMax[names[i]] + 1) * categoryFreq[names[i]]
            ), names[i]);
        }
    }

    long long ans = 0;
    set<string> addedAlready;
    while (k > 0 && !benefits.empty()) {
        auto [benefit_group, name] = benefits.top();
        benefits.pop();
        long long benefit = benefit_group.second;
        if (benefit > maxFreq) {
            k--;
            curStats[name]++;
            addedAlready.insert(name);
            ans += benefit;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!addedAlready.count(names[i])) {
            for (long long e : categoryEvents[names[i]]) if (e != categoryMax[names[i]])
                ans += curStats[names[i]];
        }
    }

    ans += maxFreq * k;
    cout << ans << endl;

    return 0;
}