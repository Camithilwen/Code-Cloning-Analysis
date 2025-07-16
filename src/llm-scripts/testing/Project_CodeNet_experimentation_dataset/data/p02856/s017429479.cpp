#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int m; cin>>m;
  vector<ll> d(m),c(m);
  for (int i=0;i<m;i++) cin>>d[i]>>c[i];
  ll res=0, digit=0;
  for (int i=0;i<m;i++) {
    res+=c[i];
    digit+=d[i]*c[i];
  }
  res=res-1+(digit-1)/9;
  cout<<res<<endl;
}
