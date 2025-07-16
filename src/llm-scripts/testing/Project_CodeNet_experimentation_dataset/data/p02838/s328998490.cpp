#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};

mint mod_pow(int i,int j)
{
  mint x=i;
  mint y=(j%2)? x:1;
  j/=2;
  while(j!=0)
  {
    x=x*x;
    if(j%2)
    {
      y=(y.x==1)? x:x*y;
    }
    j/=2;
 }
 return y;
}
int main()
{
	 
  int n;
  cin>>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  mint ans=0;
  for(int i=0;i<64;i++)
  {
    int z=0;
    int o=0;
    for(int j=0;j<n;j++)
    {
      ll t=1L<<i;
      if(t&a[j])o+=1;
      else z+=1;
    }
    //cout<<i<<" "<<o<<" "<<z<<endl;
    ans+=(mod_pow(2,i)*z*o);
    
  }
  cout<<ans.x<<endl;
  return 0;
}
    
      