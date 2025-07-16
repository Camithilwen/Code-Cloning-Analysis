#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
void read(int &x){
	char ch;bool ok;
	for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
	for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=1e5+10;
int mm,m,n,a[60];
long long f[60];
long long ans;
void dfs(int x,int n,long long sum){
	if(x==n/2+1){
		if(sum==m){
			long long now=a[1]>=0?(9-a[1]):(9+a[1]);
			for(rg int i=2;i<x;i++)now=now*(a[i]>=0?(10-a[i]):(10+a[i]));
			ans+=n&1?now*10:now;
		}
		return ;
	}
	if(sum+10ll*(f[n-x]-f[x-1])<m||sum-10ll*(f[n-x]-f[x-1])>m)return ;
	for(rg int i=-9;i<10;i++){
		a[x]=i;
		dfs(x+1,n,sum+1ll*a[x]*(f[n-x]-f[x-1]));
	}
}
int main(){
	read(m),mm=m;f[0]=1;
	while(mm)n++,mm/=10;
    for(rg int i=1;i<=18;i++)f[i]=f[i-1]*10;
	for(rg int i=n;i<=18;i++)dfs(1,i,0);
	printf("%lld\n",ans);
}
