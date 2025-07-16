#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

inline int read(){
	register int x=0,w=1,ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-48;
	return w*x;
}

int n,s,x[maxn];
long long p[maxn];

long long calc(int l,int r,int lst){
	if(s<x[l])return x[r]-s;
	if(x[r]<s)return s-x[l];
	if(p[l]>=p[r]){
		p[l]+=p[r];
		return calc(l,r-1,l)+(lst==r)*(x[r]-x[l]);
	}
	else{
		p[r]+=p[l];
		return calc(l+1,r,r)+(lst==l)*(x[r]-x[l]);
	}
}

int main(){
	n=read(),s=read();
	for(int i=1;i<=n;i++)
		x[i]=read(),p[i]=read();
	cout<<calc(1,n,p[1]<p[n]?1:n)<<'\n';
	return 0;
}