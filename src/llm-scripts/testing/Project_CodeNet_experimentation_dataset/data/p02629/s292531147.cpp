#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n;cin>>n;
  string s;
  while(n){
    n--;
    s+=(char)('a'+n%26);
    n/=26;
  }
  reverse(all(s));
  cout<<s<<endl;
}