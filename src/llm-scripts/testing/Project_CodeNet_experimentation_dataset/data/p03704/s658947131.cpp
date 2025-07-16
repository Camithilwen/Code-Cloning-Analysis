#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define For(i, j, k) for(int i = j; i <= (int)k; ++ i)
#define Forr(i, j, k) for(int i = j; i >= (int)k; -- i)
#define INF 0x3f3f3f3f
using namespace std;

ll tar, Ans = 0;
ll p[20];

inline void file(){
	freopen("arc075_F.in", "r", stdin);
	freopen("arc075_F.out", "w", stdout);
}

ll dfs(int l, int r, ll delta){
	if(l >= r)	return delta ? 0 : (l == r ? 10 : 1);
	int t = (10 - delta%10) % 10;
	ll v = delta - (t * p[r-l] - t);
	return ((l ? 10 : 9) - t) * dfs(l + 1, r - 1, abs(v) / 10);
}

int main(){
	p[0] = 1;
	For(i, 1, 18)	p[i] = p[i-1] * 10;
	scanf("%lld", &tar);
	
	For(i, 0, 18)	Ans += dfs(0, i,tar);
	
	printf("%lld", Ans);
	return 0;
}