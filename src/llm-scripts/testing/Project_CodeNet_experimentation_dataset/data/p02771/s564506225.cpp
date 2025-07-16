#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
set<ll> S;
  for(ll i=0;i<3;i++) {
ll A;
    cin>>A;
    S.insert(A);
  }
  
  if(S.size()==2) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}
