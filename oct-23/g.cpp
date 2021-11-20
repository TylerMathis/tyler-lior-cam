#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int h, w, k;
	cin >> h >> w >> k;

	struct disjointSet {
		int numberOfSets;
		vector<int> parent;
		disjointSet() { }
		disjointSet(int n) : numberOfSets(n), parent(n, -1) { }
		int find(int x) {return parent[x] < 0 ? x : parent[x] = find(parent[x]);}
		int sizeOfSet(int x) {return -parent[find(x)];}
		bool merge(int x, int y) {
			if ((x=find(x)) == (y=find(y))) return 0;
			if (parent[y] < parent[x]) swap(x, y);
			parent[x] += parent[y];
			parent[y] = x;
			numberOfSets--;
			return 1;
		}
	};

	struct Player {
		char id;

		Player(char c) : id(c) { }
	};

	vector<disjointSet>
			row(h, disjointSet(w)),
			col(w, disjointSet(h)),
			Udiag(h + w - 1, disjointSet(h + w - 1)),
			Ddiag(h + w - 1, disjointSet(h + w - 1));


	Player A('A'), B('B');

	vector<vector<char>> grid(h, vector<char>(w));

	vector<int> cols(w, h - 1);
	for (int i = 0; i < h * w; i++) {
		int c;
		cin >> c;
		c--;

		int r = cols[c];
		cols[c]--;

		auto move = [&](Player & p) -> void {

			auto win = [&](disjointSet & ds, int pos) -> void {
				if (ds.sizeOfSet(pos) >= k) {
					cout << p.id << ' ' << i + 1 << '\n';
					exit(0);
				}
			};

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if (i || j) {
						if (i + r < h && i + r >= 0 &&
								j + c < w && j + c >= 0) {
							if (grid[r + i][c + j] == p.id) {

								if (i == 0 && j != 0) { // move c
									row[r].merge(c, c + j);

									win(row[r], c);
								}

								else if (i != 0 && j == 0) { // move r
									col[c].merge(r, r + i);

									win(col[c], r);
								}

								else if (i == 1 && j == 1) { // Ddiag -> merge up
									int currDiag = r - c + w - 1;

									Ddiag[currDiag].merge(r + c, (c + j) + (r + i));

									win(Ddiag[currDiag], r + c);
								}

								else if (i == 1 && j == -1) { // Udiag -> merge down
									int currDiag = r + c;

									Udiag[currDiag].merge(r - c + w - 1, (r + i) - (c + j) + w - 1);

									win(Udiag[currDiag], r - c + w - 1);
								}

							}
						}
					}
				}
			}
		};

		if (i % 2 == 0) { // A
			grid[r][c] = A.id;

			move(A);
		}
		else { // B
			grid[r][c] = B.id;

			move(B);
		}
	}

	cout << "D\n";

	return 0;
}
