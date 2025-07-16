#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)

using ll = long long;
using namespace std;

string s;
int cnt[26];
 
int main() {
	cin >> s;
	for (auto x : s)
		cnt[x - 'a']++;
	ll res = 0;
	rep(i, 0, 25)
		rep(j, i + 1, 25)
			res += 1LL * cnt[i] * cnt[j];
	cout << res + 1 << endl;
	return 0;
}
