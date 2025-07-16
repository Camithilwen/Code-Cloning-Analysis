//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//素数判定O(√n)
bool is_prime(ll n){
  for(ll i=2;i*i<=n;i++){
    if(n%i==0)return false;
  }
  return n!=1;
}
int main(){
  ll n;cin>>n;
  vl vec;
  ll i=1;
  while(true){
    ll k=5*i+1;
    if(is_prime(k))vec.push_back(k);
    if(vec.size()==n)break;
    i++;
  }
  rep(i,n-1){
    cout<<vec[i]<<" ";
  }
  cout<<vec[n-1]<<endl;
}
