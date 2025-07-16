#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,int>>>;
#define INF 1000000000000000000
#define MOD 1000000007

int N;
vector<vector<ll>> a;
vector<bool> flag;
vector<ll> dp;

ll solve(int S){
  if(flag.at(S)){
    return dp.at(S);
  }
  flag.at(S)=true;

  ll ans=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if((((S>>i)&1)&((S>>j)&1))==1){
        ans+=a.at(i).at(j);
      }
    }
  }

  for(int T=(S-1)&S;T>0;T=(T-1)&S){
    ans=max(ans,solve(T)+solve(S^T));
  }
  return dp.at(S)=ans;
}

int main(){
  cin>>N;
  a.resize(N);
  for(int i=0;i<N;i++){
    a.at(i).resize(N);
    for(int j=0;j<N;j++){
      cin>>a.at(i).at(j);
    }
  }

  flag.resize(1<<N,false);
  dp.resize(1<<N,0);
  cout<<solve((1<<N)-1)<<endl;
}
