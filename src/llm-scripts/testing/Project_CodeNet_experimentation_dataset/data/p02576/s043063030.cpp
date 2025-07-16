#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n,x,t;
  cin>>n>>x>>t;
  int times=(n+x-1)/x;
  int ans=times*t;
  cout<<ans<<endl;
}