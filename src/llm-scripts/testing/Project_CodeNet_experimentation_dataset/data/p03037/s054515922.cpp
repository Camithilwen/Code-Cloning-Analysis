#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<int>L(m);
  vector<int>R(m);
  for(int i=0;i<m;i++){
    cin>>L.at(i)>>R.at(i);
  }
  int l=0,r=999999;
  for(int i=0;i<m;i++){
    l=max(l,L.at(i));
    r=min(r,R.at(i));
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    if(i>=l&&i<=r){
      ans++;
    }
  }
  cout<<ans<<endl;
}
