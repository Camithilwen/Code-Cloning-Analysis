#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  map<int,int> mp;
  while(N--){
    int a;
    cin>>a;
    mp[a]++;
  }
  int ans=0;
  for(auto p:mp)
    if(p.second%2)ans++;
  cout<<ans<<endl;
}