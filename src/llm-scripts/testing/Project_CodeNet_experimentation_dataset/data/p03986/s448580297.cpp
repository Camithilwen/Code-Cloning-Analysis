#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  int er=0;
  int ans=s.size();
  rep(i,s.size()){
    if(s[i]=='S') er++;
    if(s[i]=='T' && er!=0){
      er--; ans-=2;
    } 
  }
  cout<<ans<<endl;
}

