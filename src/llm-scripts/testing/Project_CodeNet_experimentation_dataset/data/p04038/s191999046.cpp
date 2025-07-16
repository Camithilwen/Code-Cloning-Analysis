#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(int i=first[x];i;i=nxt[i])
#define uu unsigned
#define fi first
#define se second
#define lam(z,k) [&](const z &a,const z &b){ return k; }
#define od(x) ((x)&1)
#define ev(x) (od(x)^1)
#define mi2(x) (1<<(x))
#define scanf a1234=scanf
int a1234;
char buf[1<<18],*bufs=buf,*buft=buf;
inline int gc(){
    return bufs==buft&&(buft=(bufs=buf)+fread(buf,1,1<<18,stdin)),bufs==buft?-1:*bufs++;
}
inline void xxx(){for(;;);}

const int mxn=2003,mod=1e9+7;
int n,k;
int dp[mxn][mxn],fac[mxn*mxn],inv[mxn*mxn];
inline int por(long long a,int b){
    long long res=1;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
inline long long C(int a,int b){return 1ll*fac[a]*inv[a-b]%mod*inv[b]%mod;}
inline long long P(int a,int b){return 1ll*fac[a]*inv[a-b]%mod;}
inline long long cha(int a,int b){return C(a+b,a);}
template<class T>inline void tsum(T &a,int b){a+=b;if(a>=mod)a-=mod;}
int main(){
    scanf("%d%d",&n,&k);if(k==1)return puts("1"),0;
    fac[0]=inv[0]=1;for(int i=1;i<=n*k;++i)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n*k]=por(fac[n*k],mod-2);for(int i=n*k-1;i;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
    dp[1][1]=1;
    for(int i=1;i<=n;++i)for(int j=i;j;--j){
        //printf("%d %d %d\n",i,j,dp[i][j]);
        tsum(dp[i][j-1],dp[i][j]);
        if(!dp[i][j])continue;
        dp[i][j]=dp[i][j]*cha((i-1)*k-j+1,k-2)%mod;
        
        tsum(dp[i+1][j+1],dp[i][j]);
//        for(int jj=1;jj<=j+1;++jj)tsum(dp[i+1][jj],dp[i][j]*cha(i*k-jj+1,k-2)%mod);//,printf("%d %d %d\n",i+1,jj,dp[i+1][jj]);
    }
    long long ans=0;
    for(int i=1;i<=n;++i)tsum(ans,dp[n][i]);
    printf("%lld\n",ans*fac[n]%mod);
    return 0;
}
