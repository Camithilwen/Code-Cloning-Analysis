#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  rep(bit,1<<3){
    int cnt=s[0]-'0';
    string t;
    t+=s[0];
    rep(i,3){
      if(bit&(1<<i)){
        cnt+=s[i+1]-'0';
        t+='+';
        t+=s[i+1];
      }
      else {
        cnt-=s[i+1]-'0';
        t+='-';
        t+=s[i+1];
      }
    }
    if(cnt==7){
      cout<<t<<"=7"<<endl;
      return 0;
    }
  }
}