#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  vector<string> s(3);
  vector<int> vec(3),cnt(3);
  int n=0;
  rep(i,3){
    cin>>s[i];
    n+=s[i].size();
    cnt[i]=s[i].size();
  }
  int x=0;
  rep(i,n){
    if(cnt[x]==vec[x]){
      cout<<(char)(x+'A')<<endl;
      return 0;
    }
    x=s[x][vec[x]++]-'a';
  }
}