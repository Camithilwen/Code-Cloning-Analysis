#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  if(s.size()==2)cout<<s;
  else rep(i, 3)cout<<s[2-i];
  return 0;
}