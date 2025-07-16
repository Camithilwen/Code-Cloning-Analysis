#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7,N=1<<20;
int n,i,ans,x,f[N],g[N],now,la[N];
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int rd(){
	int x=0,fl=1;char ch=gc();
	for(;ch<48||ch>57;ch=gc())if(ch=='-')fl=-1;
	for(;48<=ch&&ch<=57;ch=gc())x=(x<<3)+(x<<1)+(ch^48);
	return x*fl;
}
void inc(int &x,int y){x+=y;if(x>=M)x-=M;}
int main(){
    //freopen("inp","r",stdin);
	n=rd();
	for (i=1;i<N;i++) f[i]=1;
	for (i=ans=1;i<=n;i++){
		x^=rd();
		if (x) inc(f[x],1ll*(now-la[x])*g[x]%M),inc(g[x],f[x]),la[x]=now;
		else inc(ans,ans),now++;
	}
	if (x) return printf("%d",f[x]),0;
	ans=1ll*ans*(M+1>>1)%M;
	for (i=1;i<N;i++) inc(ans,g[i]);
	printf("%d",ans);
}
