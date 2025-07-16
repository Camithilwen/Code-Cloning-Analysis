#include <bits/stdc++.h>
using namespace std;


int main(){
int n,m,mx=0,mn=999999;
  cin>>n>>m;
vector<pair<int,int>> v(m);
  for(int i=0;i<m;i++){
  cin>>v[i].first>>v[i].second;
  mx=max(v[i].first,mx);
  mn=min(v[i].second,mn);
  }
  cout<<max(mn-mx+1,0);
  return 0;
}

