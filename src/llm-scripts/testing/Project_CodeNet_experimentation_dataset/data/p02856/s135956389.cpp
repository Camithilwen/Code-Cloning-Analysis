#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int M,ans=-1,g=0;
  cin>>M;
  vector<pair<int,int>> A(M);
  for(pair<int,int> &p:A){
    cin>>p.first>>p.second;
    ans+=p.second;
    g+=p.first*p.second;
  }
  cout<<ans+(g-1)/9<<endl;
}