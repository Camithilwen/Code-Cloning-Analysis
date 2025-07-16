#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int m;
  cin >> m;
  ll res = 0;
  ll sum = 0;
  rep(i,m){
    ll c,d;cin >> d >> c;
    sum += c*d;
    res += c;
  }
  res--;
  res += sum/9;
  if(sum%9 == 0)res--;
  cout << res << endl;
  
  
  


  return 0;
}
