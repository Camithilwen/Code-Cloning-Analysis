#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;
  int w;
  cin>>s>>w;

  rep(i,s.size()) if(i%w==0)cout<<s[i];

  return 0;
}