#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
bool isprime(ll n){
    if(n==1)return false;
    for (ll i = 2; i * i <= n; i++) {
        if(n%i==0)return false;
    }
    return true;
}
int main(){
  ll n;cin>>n;
  rep(i,2,55556){
    if(i%5==1&&isprime(i)){
      cout<<i<<" ";n--;
    }
    if(n==0)break;
  }
  cout<<endl;
}

