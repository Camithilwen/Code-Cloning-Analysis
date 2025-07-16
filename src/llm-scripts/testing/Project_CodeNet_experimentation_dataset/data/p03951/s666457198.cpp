#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  int n;
  string s,t;
  cin>>n>>s>>t;
  string ans=s+t;
  for(int i=n; i>=1; i--){
    string s_=s.substr(n-i, i);
    string t_=t.substr(0,i);
    if(s_==t_){ans=s.substr(0,n-i)+t;break;}
  }
  cout<<ans.size();
}