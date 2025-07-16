#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  ll ans=0;
  
  
  
  for(ll i=1;i<=min(N,K);i++) {
    
    for(ll j=0;j<=i;j++) {
      ll sum=0;
      priority_queue<ll> S;
      ll count=0;
      while(count<j) {
        sum+=vec[count];
        if(vec[count]<0) {
S.push(vec[count]*-1);
        }
        count++;
      }
      
      for(ll h=0;h<i-j;h++) {
sum+=vec[N-1-h];
        if(vec[N-1-h]<0) {
S.push(vec[N-1-h]*-1);
        }
      }
      
      ll s=i;
      while(s<K) {
        if(S.empty()) {
break;
        }
sum+=S.top();
        S.pop();
        
        s++;
      }
      
      ans=max(ans,sum);
    }
  }
    
    
    cout<<ans<<endl;
  }
      
      

      
    
    
    
    
    
    