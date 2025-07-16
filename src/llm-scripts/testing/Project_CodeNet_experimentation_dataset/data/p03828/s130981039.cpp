#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t ans=1;
  int m,j,k,y,mod=1e9+7;
  bool f;
  cin>>m;
  vector<int> p={2};
  for(j=3;j<=m;j+=2){
    f=true;
    for(k=0;k<(int)p.size();k++){
      if(j%p.at(k)==0){
        f=false;
        break;
      }
    }
    if(f==true) p.push_back(j);
  }
  int l=p.size();
  vector<int> x(l);
  for(j=2;j<=m;j++){
    y=j;
    for(k=0;k<l;k++){
      while(y%p.at(k)==0){
        x.at(k)++;
        y/=p.at(k);
      }
      if(y==1) break;
    }
  }
  for(auto z:x) ans=ans*(z+1)%mod;
  cout<<ans<<endl;
}