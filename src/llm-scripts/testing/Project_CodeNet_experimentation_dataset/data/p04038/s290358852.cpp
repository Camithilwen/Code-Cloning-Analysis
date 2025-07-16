#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
#define mp(x,y) make_pair((x),(y))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}

const int mod=1000000007;
int n,k,f[4005][2005],fac[16000005],ifc[16000005];
inline void inc(int& x,int y){x=x+y<mod?x+y:x+y-mod;}
inline void dec(int& x,int y){x=x-y>=0?x-y:x-y+mod;}
inline int power(int b,int n){int ans=1;for(;n;n>>=1,b=1ll*b*b%mod)if(n&1)ans=1ll*ans*b%mod;return ans;}
inline int C(int n,int m){return (n<0||m<0||n<m)?0:1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int main(){
	// freopen("in.in","r",stdin);
	n=read(),k=read();
	REP(i,fac[0]=1,16000001)fac[i]=1ll*fac[i-1]*i%mod;
	ifc[16000001]=power(fac[16000001],mod-2);
	DREP(i,16000001,1)ifc[i-1]=1ll*ifc[i]*i%mod;
	if(k==1)return puts("1"),0;
	f[0][0]=1;
	REP(i,0,n+n-1)REP(j,0,i>>1)if(f[i][j]){
		if(i-j>j)inc(f[i+1][j+1],f[i][j]);
		int num=(i-j)*(k-1)+j+1;
		inc(f[i+1][j],1ll*(n-i+j)*f[i][j]%mod*C(k-2+num-1,num-1)%mod);
	}
	printf("%d\n",f[n+n][n]);
	return 0;
}
