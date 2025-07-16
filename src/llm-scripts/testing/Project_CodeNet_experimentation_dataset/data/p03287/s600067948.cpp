#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,M,i,a,c = 0;scanf("%lld%lld",&N,&M);
  map<ll,ll> mp;
  mp[0] = 1;
  for(i=0;i<N;i++){
    scanf("%lld",&a);
    c = (c+a) % M;
    if(mp.find(c) != mp.end()) mp[c]++;
    else mp[c] = 1;
  }
  ll ans = 0;
  for(auto itr = mp.begin();itr != mp.end();itr++) ans += itr->second*(itr->second-1)/2;
  printf("%lld\n",ans);
}
