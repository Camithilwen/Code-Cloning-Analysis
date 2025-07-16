#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int n;
  cin >> n;
  ll taka = 0,ao = 0;
  priority_queue<Pl> que;
  vector<Pl> v(n);
  rep(i,n){
    ll a,b;cin >> a >> b;
    que.push(make_pair(a+b,i));
    v[i] = make_pair(a,b);
  }
  rep(i,n){
    Pl k = que.top();que.pop();
    if(!(i & 1))taka += v[k.second].first;
    else ao += v[k.second].second;
  }
  cout << taka-ao << endl;
  







  

  return 0;
}