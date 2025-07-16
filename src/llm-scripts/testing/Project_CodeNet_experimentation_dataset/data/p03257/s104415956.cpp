#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define ll long long
using namespace std;
const int N=50005;
int n,p[N],vis[N],cnt,now; ll a[505][505],v1[N],v2[N];
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void init(int n){
	rep (i,2,n){
		if (!vis[i]) p[++cnt]=i;
		for (int j=1;j<=cnt&&i*p[j]<=n;j++){
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
}
int main(){
	scanf("%d",&n);
	if (n==2) return puts("4 7\n23 10"),0;
	init(10000);
	rep (i,1,n) a[i][0]=a[i][n+1]=a[0][i]=a[n+1][i]=1;
	now=1;
	for (int i=1+1;i<=n+n;i+=2) v1[i]=p[now++];
	for (int i=(n&1)?1-n:2-n;i<=n-1;i+=2) v2[i+n]=p[now++];
	rep (i,1,n) rep (j,1,n) if (!((i+j)&1)) a[i][j]=v1[i+j]*v2[i-j+n];
	rep (i,1,n) rep (j,1,n) if ((i+j)&1) a[i][j]=lcm(lcm(a[i][j-1],a[i][j+1]),lcm(a[i-1][j],a[i+1][j]))+1;
	rep (i,1,n){rep (j,1,n) printf("%lld ",a[i][j]); puts("");}
	return 0;
}