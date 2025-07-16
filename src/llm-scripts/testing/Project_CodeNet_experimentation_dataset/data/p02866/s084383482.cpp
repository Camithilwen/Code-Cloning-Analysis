#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

const ll mod = 998244353;
ll modpow(ll n,ll r){
  ll res = 1;
  while(r){
    if(r & 1)res = res*n%mod;
    n = n*n%mod;
    r >>= 1;
  }
  return res;
}

int main(){

  int  n;
  cin >> n;
  vector<int> v(n,0);
  bool is = true;
  rep(i,n){
    int x;cin >> x;
    v[x]++;
    if(i == 0 && x != 0)is =false;
  }
  int mx = 0;
  rep(i,n)if(v[i] != 0)mx = i;
  ll res = 1;
  for(int i = 1;i <= mx;i++)(res *= modpow(v[i-1],v[i]))%=mod;
  if(v[0] != 1 || !is)res = 0;
  cout << res << endl;




  return 0;
}