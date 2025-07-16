#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	vector<char> r;
	for (char c : s) {
		if (r.empty() || r.back() == 'T' || c == 'S')
			r.push_back(c);
		else
			r.pop_back();
	}
	cout << len(r) << "\n";
}
