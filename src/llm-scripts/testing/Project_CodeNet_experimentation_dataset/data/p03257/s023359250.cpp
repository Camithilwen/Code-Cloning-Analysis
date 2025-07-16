#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,a[1100][1100];
int tot,p[110000]; bool vis[110000];
void init(){
	vis[1]=true;
	for (int i=2;i<=10000;i++){
		if (!vis[i]) p[++tot]=i;
		if (tot==1000) break;
		for (int j=1;j<=tot&&(i*p[j]<=10000);j++){
			vis[i*p[j]]=true;
			if (i%p[j]==0) break;
		}
	}
}
inline int lcm(int x,int y){
	if (!x||!y) return x|y;
	return x/__gcd(x, y)*y;
}
signed main(){
	init();
	scanf("%lld",&n);
	if (n==2){
		puts("4 7\n23 10");
		return 0;
	}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=n;j++)
			if (((i+j)&1)==0)
				a[i][j]=p[(i+j)/2]*p[(i-j+n+1)/2+n];
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!a[i][j]) 
				a[i][j]=lcm(lcm(a[i-1][j],a[i][j-1]),lcm(a[i][j+1],a[i+1][j]))+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<n;j++) printf("%lld ",a[i][j]);
		printf("%lld\n",a[i][n]);
	}
	return 0;	
}
