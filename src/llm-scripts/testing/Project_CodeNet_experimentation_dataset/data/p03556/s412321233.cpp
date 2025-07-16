#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(i*i>n)break;
    ans=max(ans,i*i);
  }
  cout<<ans<<endl;
}