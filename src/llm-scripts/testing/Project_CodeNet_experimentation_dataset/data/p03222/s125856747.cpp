#include<bits/stdc++.h>
using namespace std;
int64_t mod=1e9+7;
int main(){
  int64_t h,w,k,i,j;
  vector<int64_t> f(9);
  cin>>h>>w>>k;
  vector<vector<int64_t>> t(w+1,vector<int64_t>(w+1)),c(h+1,vector<int64_t>(w+1));
  f.at(0)=1;
  f.at(1)=1;
  for(i=2;i<=8;i++) f.at(i)=f.at(i-1)+f.at(i-2);
  for(i=1;i<=w;i++){
    t.at(i).at(i)=f.at(i-1)*f.at(w-i);
    if(i>1) t.at(i).at(i-1)=f.at(i-2)*f.at(w-i);
    if(i<w) t.at(i).at(i+1)=f.at(i-1)*f.at(w-i-1);
  }
  c.at(0).at(1)=1;
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      c.at(i).at(j)=c.at(i-1).at(j)*t.at(j).at(j)%mod;
      if(j>1) c.at(i).at(j)=(c.at(i).at(j)+c.at(i-1).at(j-1)*t.at(j-1).at(j))%mod;
      if(j<w) c.at(i).at(j)=(c.at(i).at(j)+c.at(i-1).at(j+1)*t.at(j+1).at(j))%mod;
    }
  }
  cout<<c.at(h).at(k)<<endl;
}