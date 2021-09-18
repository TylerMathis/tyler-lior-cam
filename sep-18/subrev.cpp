#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
vector<int> LIS(vector<T>& v) {
	if (v.size() == 0) return {};
	vector<int> p(v.size(), -1);
	vector<int> t(v.size(), 0);

	int lis = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] <= v[t[0]]) {
			t[0] = i;
		}
		else if (v[i] > v[t[lis - 1]]) {
			p[i] = t[lis - 1];
			t[lis++] = i;
		}
		else {
			int l = -1;
			int r = lis - 1;
			while ( r - l > 1) {
				int m = l + (r - l) / 2;
				if (v[t[m]] >= v[i]) r = m;
				else l = m;
			}
			p[i] = t[r - 1];
			t[r] = i;
		}
	}

	vector<int> ans;
	for (int i = t[lis - 1]; i >= 0; i = p[i]) {
		ans.push_back(i);
	}
	reverse(all(ans));
	return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto & x : a)
		cin >> x;

	vector<int> rev = a;
	reverse(all(rev));

	vector<int> lds = LIS(rev);
	for (int i = 0; i < sz(lds); i++) {
		lds[i] = n - 1 - lds[i];
	}

	for (int i = 0; i < sz(lds) / 2; i++) {
		int i1 = lds[i];
		int i2 = lds[sz(lds) - 1 - i];
		
		swap(a[i1], a[i2]);
	}

	int ans = sz(LIS(a));

	cout << ans << endl;

    return 0;
}
