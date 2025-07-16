#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
using namespace std; 
typedef long long ll; 
ll ans, fact[25]; 
int arr[25]; 
inline void chk(int len)
{
	ll res = 9 - my_abs(arr[0]); 
	for (int i = 1; i <= len - 1 >> 1; i++)
		res *= 10 - my_abs(arr[i]); 
	ans += res; 
}
void dfs(int cur, int len, ll rem)
{
	if (cur == len >> 1)
	{
		if (!rem)
		{
			arr[cur] = 0; 
			chk(len); 
		}
		return; 
	}
	ll diff = fact[len - cur - 1] - fact[cur]; 
	ll r = ceil((double)rem / diff), l = floor((double)rem / diff); 
	if (-9 <= r && r <= 9)
	{
		arr[cur] = r; 
		dfs(cur + 1, len, rem - diff * r); 
	}
	if (l != r && -9 <= l && l <= 9)
	{
		arr[cur] = l; 
		dfs(cur + 1, len, rem - diff * l); 
	}
}
int main()
{
	// freopen("ARC075-F.in", "r", stdin); 
	ll d;
	scanf("%lld", &d); 
	fact[0] = 1; 
	for (int i = 1; i <= 18; i++)
		fact[i] = fact[i - 1] * 10; 
	for (int cnt = 1; cnt <= 18; cnt++)
	{
		memset(arr, 0, sizeof(arr)); 
		dfs(0, cnt, d);
	}
	printf("%lld\n", ans);
	return 0; 
}
