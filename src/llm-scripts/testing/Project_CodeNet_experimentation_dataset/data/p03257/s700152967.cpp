#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)
typedef long long ll;

const int MAXN=505,MAXD=7919;
const int movx[4]={-1,0,1,0},movy[4]={0,1,0,-1};

int n; ll a[MAXN][MAXN];
bool vis[MAXD]; ll prime[MAXN<<1];

inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

inline ll lcm(ll a,ll b){
	if(!a||!b) return a|b;
	return a/gcd(a,b)*b;
}

inline void judge(){
	int x,a[505][505];
	scanf("%d",&x); lor(i,1,x) lor(j,1,x) scanf("%d",&a[i][j]);

}

int main(){
	scanf("%d",&n);

	if(n==2) return printf("4 7\n23 10\n"),0;

	lor(i,2,MAXD){
		if(!vis[i]) prime[++prime[0]]=i;
		for(register int j=1;j<=prime[0]&&i*prime[j]<=MAXD;++j) vis[i*prime[j]]=true;
	}

	lor(i,1,n) lor(j,1,n) if(!((i+j)&1)){
		a[i][j]=prime[(i+j)>>1]*prime[n+(n+1)/2+(i-j)/2];
	}
	lor(i,1,n) lor(j,1,n) if((i+j)&1){
		a[i][j]=lcm(lcm(a[i-1][j],a[i][j-1]),lcm(a[i+1][j],a[i][j+1]))+1;
	}
	lor(i,1,n){
		lor(j,1,n) printf("%lld ",a[i][j]); printf("\n");
	}

	return 0;
}