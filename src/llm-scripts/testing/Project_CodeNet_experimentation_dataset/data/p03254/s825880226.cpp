#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n,x;cin>>n>>x;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  sort(all(a));
  int cnt=0;
  rep(i,n){
    x-=a[i];
    if(x<0)break;
    cnt++;
  }
   if(x>0)cnt--;
  cout<<cnt<<endl;
}