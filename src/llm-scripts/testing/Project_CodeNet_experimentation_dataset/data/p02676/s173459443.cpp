#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll K; cin>>K;
  ll k = K;
  string S; cin>>S;
  
  ll i=0;
  while (S[i] && k>0){
    cout<<S[i];
    k--;
    i++;
  }
  if (S.size() > K)
    cout<<"..."<<endl;
  else
    cout<<endl;
}
