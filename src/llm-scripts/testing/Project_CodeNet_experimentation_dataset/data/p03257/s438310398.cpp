#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N  = 5100;
int n,tot; ll a[N][N];
int vis[N * 20],pri[N];
void init()
{
	vis[1] = 1;
	for(int i = 2;i <= 10000;i ++)
	{
		if(!vis[i]) pri[++ tot] = i;
		for(int j = 1;j <= tot && pri[j] * i <= 10000;j ++)
		{
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}
ll gcd(ll x,ll y){return y ? gcd(y,x % y) : x;}
ll lcm(ll x,ll y){if(!x || !y) return x | y; return x / gcd(x,y) * y;}
int main()
{
	n = read(); init();
	if(n == 2) {puts("4 7\n23 10"); return 0;}
	for(int i = 1;i <= n;i ++) 
		for(int j = (i + 1 & 1) + 1;j <= n;j += 2) 
			a[i][j] = pri[(i + j) / 2] * pri[n + (i - j) / 2 + (n + 1) / 2];
	for(int i = 1;i <= n;i ++) 
		for(int j = (i & 1) + 1;j <= n;j += 2) 
			a[i][j] = lcm(lcm(a[i - 1][j],a[i][j - 1]),lcm(a[i][j + 1],a[i + 1][j])) + 1; 
	
	for(int i = 1;i <= n;i ++,cout << "\n") for(int j = 1;j <= n;j ++) cout << a[i][j] << " ";
	return 0;
}
