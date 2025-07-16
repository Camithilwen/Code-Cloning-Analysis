#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
ll ans[1010][1010],n;
bool vis[10101];
int tot,p[10101];
inline void init(int n){
	for (int i=2;i<=n;i++){
		if (!vis[i]) p[++tot]=i;
		for (int j=1;j<=tot;j++){
			if (1ll*i*p[j]>n) break;
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
inline ll lcm(ll a,ll b){
	if (a*b==0) return a+b;
	return a/__gcd(a,b)*b;
}
signed main(){
	n=read();
	if (n==2){
		printf("4 7\n23 10\n");
		return 0;
	}
	init(10000);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if ((i+j)%2==0){
				ans[i][j]=1ll*p[(i+j)/2]*p[1+(i-j)/2+n];
			}		
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if ((i+j)%2){
				ans[i][j]=1+lcm(ans[i-1][j],lcm(ans[i][j-1],lcm(ans[i+1][j],ans[i][j+1])));
			}		
			printf("%lld ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
