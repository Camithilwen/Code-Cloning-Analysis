#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,m;cin>>n>>m;
  vector<pair<int,int>> pr(m);
  rep(i,m){
    int s,c;cin>>s>>c;
    s--;
    pr[i]=make_pair(s,c);
  }
  rep(i,1000){
    bool ans=true;
    string a=to_string(i);
    int keta=a.size();
    if(n!=keta)continue;
    rep(j,m){
      if(a[pr[j].first]!=(char)('0'+pr[j].second))ans=false;
    }
    if(ans){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}