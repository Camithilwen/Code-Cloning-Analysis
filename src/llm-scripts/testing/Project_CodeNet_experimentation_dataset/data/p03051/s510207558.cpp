#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

ll modinv(ll a) {
    ll m=Mod;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}



int main(){
  ll i,j;
  ll n;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++) cin>>a[i];
  ll sum=0;
  for(i=0;i<n;i++){
      sum=sum^a[i];
  }


      ll tmp=0;
      ll z=1;
      ll q=modinv(2);
      vector<ll> v0(1<<20,1),v1(1<<20,0);
      vector<ll> vz(1<<20,0);

      for(i=0;i<n;i++){
          tmp=tmp^a[i];
          if(tmp==0){
              z++;
              q*=2;
              q%=Mod;
          }
          else {
              v0[tmp]+=v1[tmp]*(z-vz[tmp]);
              v0[tmp]%=Mod;
              v1[tmp]+=v0[tmp];
              v1[tmp]%=Mod;
              vz[tmp]=z;

          }
      }

      if(sum!=0) {
          cout<<v0[sum]<<endl;
      }

      else {
          ll ans=0;
          for(i=0;i<(1<<20);i++) ans+=v1[i];
          cout<<(ans+q)%Mod<<endl;
      }
     

  return 0;
}