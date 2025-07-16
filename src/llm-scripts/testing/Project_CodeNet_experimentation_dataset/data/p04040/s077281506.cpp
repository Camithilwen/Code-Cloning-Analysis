#include<bits/stdc++.h>
#define int long long
#define rg register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=200000+10;
const int mod=1e9+7;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
int inv[N],jc[N];
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m){
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
int calc(int x,int y,int X,int Y){
	int n=abs(X-x),m=abs(Y-y);
	return C(n+m,n);
}
main(){
    //file("");
	jc[0]=1;
	for(int i=1;i<=N-10;i++)
		jc[i]=jc[i-1]*i%mod;
	inv[N-10]=ksm(jc[N-10],mod-2);
	for(int i=N-11;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	int H=read(),W=read(),A=read(),B=read(),ans=calc(1,1,H,W);
	for(int i=H-A+1;i<=H;i++)
		ans=(ans-calc(1,1,i,B)*calc(i,B+1,H,W)%mod+mod)%mod;
	cout<<ans;
    return 0;
}