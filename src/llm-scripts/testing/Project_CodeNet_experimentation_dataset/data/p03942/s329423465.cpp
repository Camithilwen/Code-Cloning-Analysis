#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
vi pl[26];
int ff[maxn];
int lb(int a) {
	return a & -a;
}
int d[maxn];
int q(int pl) {
	int ans = 0;
	while (pl) {
		ans = max(ans, d[pl]);
		pl -= lb(pl);
	}
	return ans;
}
void upd(int pl, int num) {
	while (pl < maxn) {
		d[pl] = max(d[pl], num);
		pl += lb(pl);
	}
}
char s[maxn], t[maxn];
int main() {
	int n;
	cin >> n;
	scanf("%s", s);
	scanf("%s", t);
	for (int i = 0; i < n; i++)
		pl[s[i] - 'a'].pb(i);
	int fl = 1;
	for (int i = 0; i < n; i++)
		if (s[i] != t[i]) fl = 0;
	if (fl) {
		cout << 0 << endl;
		return 0;
	}
	int nx = maxn;
	for (int i = n - 1; i >= 0; i--) {
		if (i && t[i] == t[i - 1]) continue;
		int ed = min(i + 1, nx); // <= i < nx
		int x = lower_bound(pl[t[i] - 'a'].begin(), pl[t[i] - 'a'].end(), ed) - pl[t[i] - 'a'].begin();//lower_bound(p
	
		if (!x) {
			printf("-1\n");
			return 0;
		}
		x--;
		ff[i] = pl[t[i] - 'a'][x], nx = ff[i];	
	//	cout << i << ' ' << x << ' ' << ff[i] << endl;
	}
	vi s;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i && t[i] == t[i - 1]) continue;
		cnt++;
		int bg = i - cnt;
		s.pb(bg);
		int uu = ff[i] - cnt;
		int nans = upper_bound(s.begin(), s.end(), uu) - s.begin();
		ans = max(ans, cnt - nans);
	}
	ans++;
	cout << ans << endl;
	return 0;
}
