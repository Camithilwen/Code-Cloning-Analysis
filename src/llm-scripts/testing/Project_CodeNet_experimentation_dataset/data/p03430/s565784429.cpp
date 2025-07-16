#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //printf(f,##__VA_ARGS__),fflush(stdout)

typedef long long ll;

const int N=305;

int qk,f[N][N][N],n;
char s[N];

int dp(int l,int r,int k){
	if(l>r)return 0;
	if(l==r)return 1;
	if(f[l][r][k]!=-1)return f[l][r][k];
	int &res=f[l][r][k];
	res=0;
	if(s[l]==s[r])res=max(res,dp(l+1,r-1,k)+2);
	res=max(res,dp(l+1,r,k));
	res=max(res,dp(l,r-1,k));
	if(k)res=max(res,dp(l+1,r-1,k-1)+2);
	Pr("f(%d,%d,%d)=%d\n",l,r,k,f[l][r][k]);
	return res;
}

int main(int argc,char *argv[]){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&qk);
	memset(f,-1,sizeof(f));
	cout<<dp(1,n,qk)<<endl;
	return 0;
}
