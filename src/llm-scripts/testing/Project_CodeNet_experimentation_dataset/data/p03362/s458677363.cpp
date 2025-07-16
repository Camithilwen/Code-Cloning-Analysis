#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,cnt=0;cin>>n;
  lvector ans;
  bool is_prime;
  for(ll i=2;i<=55555;i++) {
    if(i%5!=1) continue;
    is_prime=true;
    for(ll div=2;div*div<=i;++div) 
      if(i%div==0) {is_prime=false;break;}
    if(is_prime) {ans.emplace_back(i);cnt++;}
    if(cnt==n) break;
  }
  rep(i,n-1) cout<<ans[i]<<' ';print(ans[n-1]);
  return 0;
}