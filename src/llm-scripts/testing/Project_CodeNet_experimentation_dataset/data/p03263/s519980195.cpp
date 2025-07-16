#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>


int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> c(h,vector<int>(w));
  vector<pair<int,P>> coin;
  rep(i,h){
    rep(j,w) cin>>c[i][j];
    if(i%2==1) reverse(c[i].begin(),c[i].end());
  }
  rep(i,h)rep(j,w){
    if(i%2==0) coin.push_back(make_pair(c[i][j],make_pair(i+1,j+1)));
    else coin.push_back(make_pair(c[i][j],make_pair(i+1,w-j)));
  }
  vector<pair<P,P>> ans; 
  rep(i,h*w-1){
    if(coin[i].first%2 == 1){
      coin[i+1].first++;
      ans.push_back(make_pair(make_pair(coin[i].second.first,coin[i].second.second),make_pair(coin[i+1].second.first,coin[i+1].second.second)));
    }
  }
  cout<<ans.size()<<endl;
  for(auto x : ans){
    cout<<x.first.first<<" "<<x.first.second<<" "<<x.second.first<<" "<<x.second.second<<endl;
  }
}

