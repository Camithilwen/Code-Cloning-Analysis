#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define maxn 1000010

using namespace std;
typedef long long llg;

struct data{
	int l,r;
	data(int a=0,int b=0):l(a),r(b){}
}s[maxn];
int *q[26],lq[26],ct[26],n;
int R[maxn],ls,d[maxn];
char S[maxn],T[maxn];

int erfen(int *a,int r,int x){
	int l=0,mid;
	while(l!=r){
		mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}

int main(){
	scanf("%d",&n);
	scanf("%s\n%s",S+1,T+1);
	for(int i=1;i<=n;i++) ct[S[i]-'a']++;
	for(int i=0;i<26;i++) q[i]=new int[ct[i]+10];
	for(int i=1,x;i<=n;i++)
		x=S[i]-'a',q[x][++lq[x]]=i;
	for(int i=0;i<26;i++) q[i][++lq[i]]=n+1,q[i][0]=0;
	for(int i=n,x,y,l=n;i;i--){
		x=T[i]-'a'; l=min(l,i);
		y=q[x][erfen(q[x],lq[x],l+1)-1];
		if(!y) return printf("-1"),0;
		if(!R[y]) R[y]=i; if(y<l) l=y;
	}
	for(int i=1;i<=n;i++)
		if(R[i]) s[++ls]=data(i,R[i]),d[ls]=i-ls;
	s[++ls]=data(n*2,n*2),d[ls]=n*2-ls;
	int ans=0;
	for(int i=1,j=1;i<=ls;i++){
		while(d[j]<s[i].r-i) j++;
		ans=max(ans,j-i);
	}
	printf("%d",ans);
	return 0;
}