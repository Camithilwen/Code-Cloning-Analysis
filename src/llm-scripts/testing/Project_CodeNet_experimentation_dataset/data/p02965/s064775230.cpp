#include <cstdio>

const long long mod=998244353ll;

const int MSIZE=4000000;


void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long iv(long long a){return pw(a,mod-2);}
long long inv[MSIZE],F[MSIZE],iF[MSIZE];

void prev(int N)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
  F[0]=iF[0]=1;
  for(int i=1;i<N;i++){
    F[i]=F[i-1]*i%mod;
    iF[i]=iF[i-1]*inv[i]%mod;
  }
}

long long Ch(int i,int j)
{
  return i<0||j<0||i<j?0:F[i]*iF[j]%mod*iF[i-j]%mod;
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  prev(n+3*m);
  long long ans=Ch(3*m+n-1,n-1);
  mn(ans,n*Ch(m-1+n-1,n-1)%mod);
  for(int i=m+1;i<=3*m&&i<=n;i++){
    if((3*m-i)%2==0){
      mn(ans,Ch(n,i)*Ch((3*m-i)/2+n-1,n-1)%mod);
    }
  }
  printf("%lld\n",ans);
  return 0;
}
