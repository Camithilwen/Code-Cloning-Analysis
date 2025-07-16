#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,K,mx=0,gc=0;
  cin>>N>>K;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    mx=max(mx,i),gc=__gcd(gc,i);
  }
  if(K<=mx && K%gc==0)puts("POSSIBLE");
  else puts("IMPOSSIBLE");
}