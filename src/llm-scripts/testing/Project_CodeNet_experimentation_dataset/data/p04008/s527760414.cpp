#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k, ans;
int a[maxn];
bool sec[maxn];
vector<int> E[maxn];
int dfs(int x)
{
	int ret = 0;
	for(auto v : E[x])
		ret = max(ret, dfs(v));
	++ret;
	if(ret == k && !sec[x]) ++ans, ret = 0;
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k); 
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	ans += (a[1] != 1);
	for(int i = 2; i <= n; ++i) E[a[i]].push_back(i);
	sec[1] = 1;
	for(auto v : E[1]) sec[v] = 1;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}