#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<string> dict;
	string s;
	while (cin >> s)
		dict.push_back(s);

	int b = stoi(dict.back());
	dict.pop_back();
	int a = stoi(dict.back());
	dict.pop_back();

	for (auto & s : dict)
		cout << s << ' ';
	cout << endl;
	cout << a << ' ' << b << endl;

	return 0;
}
