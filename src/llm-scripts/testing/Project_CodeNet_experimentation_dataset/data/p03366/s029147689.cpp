#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n, s;
ll ans;
int x[maxn];
ll p[maxn];
ll ttm[maxn];
int ls[maxn], pp[maxn];
void caltm(int a) {
	if (!ls[a]) return ;
	else if (ttm[a]) return ;
	else caltm(ls[a]), ttm[a] = ttm[ls[a]] + pp[a];
}
int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &p[i]);
	int l = 1, r = n;
	while (1) {
		if (s <= x[l] || s >= x[r]) {
			for (int i = l; i <= r; i++)
				ttm[i] = abs(s - x[i]);
			break;
		}
		if (p[l] >= p[r]) {
			ls[r] = l, pp[r] = x[r] - x[l];
			p[l] += p[r], r--;
		}
		else {
			ls[l] = r, pp[l] = x[r] - x[l];
			p[r] += p[l], l++;
		}
	}
	for (int i = 1; i <= n; i++)
		caltm(i), ans = max(ans, ttm[i]);//, cout << ttm[i] << ' ' << ls[i] << ' ' << pp[i] << endl;
	cout << ans << endl;
	return 0;
}
