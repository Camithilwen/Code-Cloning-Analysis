#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  vector<ll> vecA(N);
  rep(i,N)
  {
    cin>>vecA.at(i);
  }
  sort(vecA.begin(),vecA.end());
  reverse(vecA.begin(),vecA.end());
  ll L=0;
  rep(i,N-1)
  {
    if(vecA.at(i)==vecA.at(i+1))
    {
      if(L==0) {L=vecA.at(i); i++; continue;}
      cout<<L*vecA.at(i)<<endl; return 0;
    }
  } 
  cout<<0<<endl;
  return 0;
}