#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rel register ll
#define rec register char
#define gc getchar
//#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?-1:*p1++)
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
char buf[1<<23],*p1=buf,*p2=buf;
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return 0&pc(48);
  if (x<0) pc('-'),x=-x;
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int aoi=2038,mod=1e9+7;
ll dp[aoi],inv[aoi];

ll kasumi(ll a,ll b=mod-2) {
ll s=1;
for (;b;b>>=1,a=a*a%mod) if (b&1) s=s*a%mod;
return s;
}

int main() {
int n,a,b,c,d,i,j,k;
read(n),read(a),read(b),read(c),read(d);
for (dp[n]=i=1;i<=n;++i) dp[n]=dp[n]*i%mod;
inv[n]=kasumi(dp[n]);
for (i=n;i;--i) inv[i-1]=inv[i]*i%mod;
for (i=a;i<=b;++i)
  for (j=0;j<=n;++j) 
    for (k=c;k<=d&&j+i*k<=n;++k) 
      dp[j]=(dp[j]+dp[j+i*k]*kasumi(inv[i],k)%mod*inv[k]%mod)%mod;
cout<<*dp<<"\n";
}