#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n;
  cin >>n;
  map<int,int>mp;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    mp[a]++;
    mp[a]%=2;
  }
  long long kotae=0;
  auto begin=mp.begin(),end=mp.end();
  for(auto iter=begin;iter!=end;iter++){
    int x=iter->second;
    if(x==1)kotae++;
  }
  cout<<kotae<<endl; 
  return 0;
}
  
  
