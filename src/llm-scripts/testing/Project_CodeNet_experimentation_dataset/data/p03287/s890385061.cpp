#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for (ll i=0; i<N; i++){
    cin >> A[i];
  }
  ll temp=0;

  map<ll,ll> count;
  vector<ll> elem;

  count[0]=1;
  elem.push_back(0);
  for (ll i: A){
    temp=(temp+i)%M;
    //cout<<temp<<endl;
    if (count.find(temp)!=count.end()){
      count[temp]++;
    } else{
      count[temp]=1;
      elem.push_back(temp);
    }
  }
  ll ans=0;
  for (ll i=0; i<elem.size(); i++){
    ll curr=count[elem[i]];
    ans+=(long long) curr*(curr-1)/2;
  }
  cout<<ans<<endl;
 
} 
