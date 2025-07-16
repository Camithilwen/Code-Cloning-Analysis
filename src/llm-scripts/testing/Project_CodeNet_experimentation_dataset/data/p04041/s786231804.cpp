#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=42, Max=(1<<17)+10, MOD=1e9+7;
ll n, x, y, z, f[N][Max], sum=1, ans;
inline ll M(ll a){return a%MOD;}

void work(){
	for(int i = 0; i < n; i++) sum = M(sum*10);
	ll cnt = (1<<x+y+z) -1;
	ll tot = (1<<x-1) | (1<<x+y-1) | (1<<x+y+z-1); 
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) 
		for(int j = 0; j <= cnt; j++) 
			for(int h = 1;h <= 10; h++){
				ans = (j<<h)|(1<<h-1);
				ans &= cnt;
				if((ans&tot)!=tot) f[i][ans] = M(f[i][ans]+f[i-1][j]);
			}
	for(int i = 0; i <= cnt; i++)
		sum = M(sum-f[n][i]+MOD);
}

int main(){
	scanf("%lld%lld%lld%lld",&n,&x,&y,&z);
	work();
	printf("%lld",sum);
	return 0;
}