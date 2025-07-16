#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll A,B;
  cin>>A>>B;
  ll ans=1;
  for(ll i=2;i<=sqrt(min(A,B));i++) {
if(A%i==0&&B%i==0) {
ans++;
}
    if(A%i==0) {
while(A%i==0) {
A/=i;
}
    }
    
    if(B%i==0) {
while(B%i==0) {
B/=i;
}
    }
  }
  
  
  if(A>1&&B>1) {
if(A%B==0||B%A==0) {
ans++;
}
  }
  
  
  cout<<ans<<endl;
}
  
  
  
  
  
  
  
  
  
  
  
  