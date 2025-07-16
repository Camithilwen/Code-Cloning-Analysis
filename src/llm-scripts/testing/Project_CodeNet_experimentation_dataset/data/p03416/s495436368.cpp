#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll A,B;
  cin>>A>>B;
  ll ans=0;
  for(ll i=A;i<=B;i++) {
string S=to_string(i);
    if(S[0]==S[4]&&S[1]==S[3]) {
ans++;
    }
  }
  
  cout<<ans<<endl;
}