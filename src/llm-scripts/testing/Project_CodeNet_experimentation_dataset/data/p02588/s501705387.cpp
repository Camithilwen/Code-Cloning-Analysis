#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

int bs(ll k,vector<ll> & v){
  int l = -1,r = v.size();
  while(r-l > 1){
    int mid = (l+r)/2;
    if(v[mid] < k)l = mid;
    else r = mid;
  }
  return r;
}

int main(){
  
  ll n;
  cin >> n;
  vector<vector<ll>> v(30);
  vector<P> w(n);
  rep(i,n){
    string s;cin >> s;
    ll a = 0,b = 0,digit = 0;
    rep(k,s.size()){
      if(s[k] == '.'){
        for(ll j = k+1;j < s.size();j++)b = b*10+s[j]-'0',digit++;
        break;
      }
      a = a*10+s[k]-'0';
    }
    a *= 1000000000ll;
    rep(g,9-digit)b *= 10ll;
    a += b;
    ll two = 0,five = 0;
    while(!(a & 1))two++,a >>= 1;
    while(!(a % 5))five++,a /= 5;
    w[i] = make_pair(five,two);
    v[five].push_back(two);
  }
  rep(i,30)sort(ALL(v[i]));
  ll res = 0;
  rep(i,n){
    ll k = max(0,18-w[i].first);
    for(ll j = k;j < 30;j++){
      ll pos = max(0,bs(18-w[i].second,v[j]));
      ll l = v[j].size();
      res += l - pos;
    }
    if(w[i].first >= 9 && w[i].second >= 9)res--;
  }
  res >>= 1;
  cout << res << "\n";
  

  return 0;
}