#include <bits/stdc++.h>
#define int long long
using namespace std;

enum DIRECTION {RIGHT, LEFT};

vector<string> solved = {
	"RRRR",
	"GGGG",
	"BBBB",
	"YYYY"
};

void rotate_right(string & s) {
	char prev = s[0];
	s[0] = s[3];
	for (int i = 1; i < 4; i++)
		swap(s[i], prev);
}

void rotate_left(string & s) {
	char prev = s[3];
	s[3] = s[0];
	for (int i = 2; i >= 0; i--)
		swap(s[i], prev);
}

void push(queue<vector<string>> & q, vector<string> & u,
		map<vector<string>, int> & d, int dv) {

	if (!d.count(u)) {
		q.push(u);
		d[u] = dv + 1;
	}

}

void search_adj_dir(queue<vector<string>> & q, vector<string> & v,
		map<vector<string>, int> & d, int dv, DIRECTION dir) {

	// rotate each row
	for (auto & s : v) {

		// rotate
		if (dir == RIGHT)
			rotate_right(s);
		else
			rotate_left(s);

		push(q, v, d, dv);

		// unrotate
		if (dir == RIGHT)
			rotate_left(s);
		else
			rotate_right(s);
	}

	// rotate each col
	for (int i = 0; i < 4; i++) {

		// extract the col
		string col = "";
		for (int j = 0; j < 4; j++)
			col += v[j][i];

		if (dir == RIGHT)
			rotate_right(col);
		else
			rotate_left(col);

		// replace the col
		for (int j = 0; j < 4; j++)
			v[j][i] = col[j];

		push(q, v, d, dv);

		// unrotate
		if (dir == RIGHT)
			rotate_left(col);
		else
			rotate_right(col);

		// replace the col
		for (int j = 0; j < 4; j++)
			v[j][i] = col[j];
	}
}

void search_adj(queue<vector<string>> & q, vector<string> & v,
		map<vector<string>, int> & d, int dv) {
	search_adj_dir(q, v, d, dv, RIGHT);
	search_adj_dir(q, v, d, dv, LEFT);
}

void push_adj(queue<vector<string>> & q, vector<string> & v,
		map<vector<string>, int> & d_start,
		map<vector<string>, int> & d_end, int dv) {

	if (d_start.count(v) && d_end.count(v)) {
		cout << d_start[v] + d_end[v] << endl;
		exit(0);
	}

	if (d_start.count(v))
		search_adj(q, v, d_start, dv);

	if (d_end.count(v))
		search_adj(q, v, d_end, dv);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
	vector<string> initial_state(4);
	for (auto & s : initial_state)
		cin >> s;

	queue<vector<string>> q;
	map<vector<string>, int> d_start, d_end;

	q.push(initial_state);
	d_start[initial_state] = 0;

	q.push(solved);
	d_end[solved] = 0;

	while (!q.empty()) {
		auto v = q.front();
		q.pop();

		int dv;
		if (d_start.count(v))
			dv = d_start[v];
		else
			dv = d_end[v];
		push_adj(q, v, d_start, d_end, dv);
	}

    return 0;
}
