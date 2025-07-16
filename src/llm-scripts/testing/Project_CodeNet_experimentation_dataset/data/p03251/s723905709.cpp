#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  ll c=-100;
  ll d=100;
  ll e,f;
  cin>>e>>f;
  for(ll i=0; i<a;i++){
    ll g;
    cin>>g;
    c=max(g,c);
  }
  for(ll i=0;i<b;i++){
    ll h;
    cin>>h;
    d=min(h,d);
  }
  if(c+1>d){
    cout<<"War"<<endl;
    return 0;
  }
  
    for(ll i=e+1;i<=f;i++){
      if(c+1<=i&&i<=d){
        cout<<"No War"<<endl;
        return 0;
      }
    }
    cout<<"War"<<endl;
  return 0;
}
