/*====Corycle====*/
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<map>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=1e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a,b,Ans,fac[N],inv[N];
int mod(int x){return x>=Mod?x-Mod:x;}
void Prepare(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	for(int i=2;i<N;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
}
int C(int n,int m){return n<m?0:1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int F(int n,int m){return C(n+m-2,n-1);}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();a=read();b=read();Prepare();
	for(int i=1;i<=n-a;i++)Ans=mod(Ans+1ll*F(i,b)*F(n-i+1,m-b)%Mod);
	printf("%d\n",Ans);
	return 0;
}