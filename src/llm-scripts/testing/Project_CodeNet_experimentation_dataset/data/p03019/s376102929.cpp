#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout << "[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]\n"
#define rd() abs((int)rng())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
ll X, b[maxn], l[maxn], r[maxn], base;
vector<pair<ll, int> >sums;
bool can(ll c)
{
	ll full = c / X, rem = c - full * X;
	ll sum = 0;
	for(int i = 0; i < full; i++)
		sum += sums[i].x;
	ll mx = 0;
	for(int i = 0; i < n; i++)
	{
		int j = sums[i].y;
		ll add;
		if(rem >= b[j])
			add = b[j] * l[j] + r[j] * (rem - b[j]);
		else
			add = l[j] * rem;
		if(i < full)
			mx = max(mx, sum - sums[i].x + add + (full == n ? 0 : sums[full].x));
		else
			mx = max(mx, sum + add);
	}
	return mx >= base;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n >> X;
	for(int i = 0; i < n; i++)
	{
		cin >> b[i] >> l[i] >> r[i];
		base += l[i] * b[i];
		sums.pb({(X - b[i]) * r[i] + b[i] * l[i], i});
	}
	sort(all(sums), greater<pair<ll, int> >());
	ll lo = 0, hi = X * n;
	while(lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if(can(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo << "\n";
	return 0;
}