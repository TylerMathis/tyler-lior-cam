#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NT = 101;
const int NP = 21;
const int NS = 10'000;
const int NR = NT;

signed main() {
	vector<vector<int>> A(NT, vector<int>(NP));
	vector<vector<bool>> B(NT, vector<bool>(NP));

	int nt, np, ns, nr;
	cin >> nt >> np >> ns >> nr;

	for (int i = 0; i < ns; i++) {
		int T, P, t, D;
		cin >> T >> P >> t >> D;
		if (t >= 300)
			continue;
		if (!B[T][P]) {
			if (D)
				A[T][P] += t;
			else
				A[T][P] += 20;

			B[T][P] = D;
		}
	}

	vector<tuple<int, vector<int>, int>> ord;
	for (int team = 1; team <= nt; team++) {
		ord.emplace_back();
		get<2>(ord.back()) = team;
		for (int problem = 1; problem <= np; problem++) {
			if (B[team][problem]) {
				get<1>(ord.back()).push_back(A[team][problem]);
			}
		}
		sort(rbegin(get<1>(ord.back())), rend(get<1>(ord.back())));
		get<0>(ord.back()) = accumulate(begin(get<1>(ord.back())), end(get<1>(ord.back())), 0ll);
	}

	auto cmp = [](const auto & a, const auto & b) {
		if (size(get<1>(a)) == size(get<1>(b))) {
			if (get<0>(a) == get<0>(b)) {
				if (get<1>(a) == get<1>(b)) {
					return get<2>(a) < get<2>(b);
				}
				return get<1>(a) < get<1>(b);
			}
			return get<0>(a) < get<0>(b);
		}
		return size(get<1>(a)) > size(get<1>(b));
	};

	sort(begin(ord), end(ord), cmp);

	ord.emplace_back();

	int place = 1;
	int passed = 1;
	int i = 0;
	while (i < (int) size(ord) && place <= nr) {
		auto & [time, problems, team] = ord[i];
		printf("%-4lld", place);
		printf("%-4lld", team);
		printf("%3lld", (int) size(problems));
		printf("%5lld", time);
		printf("\n");
		if (get<0>(ord[i]) == get<0>(ord[i + 1]) && get<1>(ord[i]) == get<1>(ord[i + 1])) {
			passed++;
		} else {
			place += passed;
			passed = 1;
		}
		i++;
	}

	return 0;
}
