#include<iostream>
#include<cstdio>
using namespace std;
int n,S,X[202020],st[202020],top;
long long P[202020];
void solve(int l,int r)
{
	if(S<=X[l]) return (void)(st[++top]=r);
	if(S>=X[r]) return (void)(st[++top]=l);
	if(P[l]<P[r]) return st[++top]=l,P[r]+=P[l],solve(l+1,r);
	else return st[++top]=r,P[l]+=P[r],solve(l,r-1);
}
int aabs(int x){ return x<0?-x:x;}
int main()
{
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++)
	scanf("%d%lld",&X[i],&P[i]);
	solve(1,n);
	long long ans=0;
	while(top) ans+=aabs(S-X[st[top]]),S=X[st[top--]];
	printf("%lld\n",ans);
	return 0;
}