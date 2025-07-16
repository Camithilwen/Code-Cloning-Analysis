#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  ll N,A,B,ans=0;
  cin>>N>>A>>B;
  ll x[N];
  for(ll i=0;i<N;i++) cin>>x[i];
  for(ll i=0;i<N-1;i++){
    if((x[i+1]-x[i])*A>B) ans+=B;
    else ans+=(x[i+1]-x[i])*A;
  }
  cout<<ans<<endl;
}
