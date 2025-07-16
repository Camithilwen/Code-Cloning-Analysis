#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,M;
  cin>>N>>M;
  map<int,int> mp;
  mp[0]=1;
  int n=0;
  while(N--){
    int a;
    cin>>a;
    n=(n+a)%M;
    mp[n]++;
  }
  int ans=0;
  for(pair<int,int> p:mp)ans+=p.second*(p.second-1)/2;
  cout<<ans<<endl;
}