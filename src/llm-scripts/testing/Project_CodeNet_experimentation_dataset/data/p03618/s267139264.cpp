#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main(){
  string S;
  cin>>S;
  ll N = S.size();
  map<char,ll> m;
  for(ll i = 0; i < N; i++) m[S[i]]++;
  ll ans = 0LL;
  for(auto x:S){
    ans+=N-m[x];
  }
  cout<<ans/2+1<<endl;
}