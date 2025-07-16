#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  vector<vector<pair<ll,ll>>> vec(N,vector<pair<ll,ll>>(0));
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    for(ll j=0;j<A;j++) {
ll x,y;
      cin>>x>>y;
      vec[x-1].push_back(make_pair(i+1,y));
    }
  }
  
  
  ll ans=0;
  for(ll tmp=0;tmp<(1<<N);tmp++) {
bitset<15> S(tmp);
    bool a=true;
    
    for(ll i=0;i<N;i++) {
      ll k;
      if(S.test(i)) {
k=1;
      }
      else {
        k=0;
      }
for(auto x:vec[i]) {
  if(S.test(x.first-1)) {
  if(x.second!=k) {
a=false;
  }
}
      
}
    }

    if(a) {
      ll sum=S.count();
ans=max(ans,sum);
    }
  }
  
  
  
  
  cout<<ans<<endl;
}
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  