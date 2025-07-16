#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int n;
int a[maxn], prep[maxn], sufp[maxn];
ll ans = 1e18;
ll pre[maxn], suf[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	int cur = 1;
	pre[1] = a[1];
	for(int i = 2; i <= n; ++i) 
	{
		pre[i] = pre[i - 1] + a[i];
		while(pre[cur] * 2 <= pre[i]) ++cur;
		prep[i] = cur - 1;
	}
	
	cur = n;
	suf[n] = a[n];
	for(int i = n - 1; i; --i)
	{
		suf[i] = suf[i + 1] + a[i];
		while(suf[cur] * 2 <= suf[i]) --cur;
		sufp[i] = cur - 1;
	}
	
	for(int i = 3; i < n; ++i)
	{
		int l2 = i - 1;
		for(int j = 0; j < 2; ++j)
			for(int k = 0; k < 2; ++k)
			{
				int l1 = prep[i - 1] + j;
				int l3 = sufp[i] + k;
				if(l1 < l2 && l2 < l3 && l3 < n)
				{
					ll x1 = pre[l1], x2 = pre[l2] - pre[l1], x3 = pre[l3] - pre[l2], x4 = pre[n] - pre[l3];
					//cout << i << ' ' << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << endl;
					ans = min(ans, max(max(x1, x2), max(x3, x4)) - min(min(x1, x2), min(x3, x4)));
				}
			}
	}
	printf("%lld\n", ans);
	return 0;
}
			
		
	