#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 500;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int c;
	cin >> c;
	unordered_map<string, int> tops;
	tops.reserve(N);
	vector<tuple<vector<int>, bool, int>> cond; // stores [vars, oper, earn] - and = 1, or = 0

	unordered_set<int> taken;
	taken.reserve(N);

	auto add = [&](string s) {
		if (!tops.count(s))
			tops[s] = size(tops);
		return tops[s];
	};

	for (int i = 0; i < c; i++) {
		string s;
		cin >> s;
		if (s == "if") {
			cond.emplace_back();
			cin >> s;
			while (s != "then") {
				if (s == "and") {
					get<1>(cond.back()) = 1;
				} else {
					get<0>(cond.back()).push_back(add(s));
				}
				cin >> s;
			}
			cin >> s;
			get<2>(cond.back()) = add(s);
		} else {
			taken.insert(add(s));
		}
	}

	bool added;
	do {
		added = 0;
		for (auto & [vars, oper, earn] : cond) {
			if (taken.count(earn))
				continue;

			bool eval = oper;
			for (const auto & var : vars) {
				if (oper)
					eval &= taken.count(var);
				else
					eval |= taken.count(var);
			}

			if (eval) {
				taken.insert(earn);
				added = 1;
			}
		}
	} while (added);

	cout << size(taken) << '\n';

	return 0;
}
