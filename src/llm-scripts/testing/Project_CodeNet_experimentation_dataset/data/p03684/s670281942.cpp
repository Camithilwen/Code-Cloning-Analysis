#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int p[100010];
vector<pair<ll,ll>> vt;
vector<pair<ll, ll>> vt1;
vector<pair<ll, pair<ll, ll>>> vt2;
int find(int u)
{
	if (u == p[u])return u;
	return p[u] = find(p[u]);
}
int merge(int u, int v)
{
	u = find(u), v = find(v);
	if (u == v)return 0;
	p[u] = v;
	return 1;
}
int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		ll q, w;
		scanf("%lld %lld", &q, &w);
		vt.push_back({ q,i });
		vt1.push_back({ w,i });
	}
	sort(vt.begin(), vt.end());
	sort(vt1.begin(), vt1.end());
	for (int i = 1; i < n; i++)
	{
			vt2.push_back({vt[i].first-vt[i-1].first ,{ vt[i].second,vt[i - 1].second } });
			vt2.push_back({ vt1[i].first - vt1[i - 1].first ,{ vt1[i].second,vt1[i - 1].second } });
	}
	sort(vt2.begin(), vt2.end());
	ll dap = 0;
	for (int i = 0; i < vt2.size(); i++) {
		if (merge(vt2[i].second.first, vt2[i].second.second))
		{
			dap += vt2[i].first;
		}
	}
	printf("%lld", dap);
}