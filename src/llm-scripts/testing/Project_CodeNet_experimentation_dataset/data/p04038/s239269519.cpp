#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define rg register
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=2010,mod=1e9+7,N=4e6;
int n,m,f[maxn][maxn],fac[maxn*maxn],inv[maxn*maxn];
int mul(int x,int y){return 1ll*x*y-1ll*x*y/mod*mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int del(int x,int y){return x-y<0?x-y+mod:x-y;}
int mi(int a,int b){int ans=1;while(b){if(b&1)ans=mul(ans,a);b>>=1,a=mul(a,a);}return ans;}
void prepare(){
    fac[0]=inv[0]=1;
    for(rg int i=1;i<=N;i++)fac[i]=mul(fac[i-1],i);
    inv[N]=mi(fac[N],mod-2);
    for(rg int i=N-1;i;i--)inv[i]=mul(inv[i+1],i+1);
}
int C(int n,int m){return mul(fac[n],mul(inv[m],inv[n-m]));}
int main(){
    read(n),read(m),prepare();
    if(m==1)return printf("1\n"),0;
    for(rg int i=1;i<=n;i++){
	f[i][0]=1;
	for(rg int j=1;j<=i;j++)
	    f[i][j]=add(f[i-1][j],mul(mul(f[i][j-1],n-j+1),C(n*m-(j-1)*(m-1)-i-1,m-2)));
    }
    printf("%d\n",f[n][n]);
}
