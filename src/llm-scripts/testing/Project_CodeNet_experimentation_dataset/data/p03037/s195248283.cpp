#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
  int mx=INT_MIN, mn=INT_MAX;
  for(int i=0;i<m;i++){
    int l,r; cin>>l>>r;
    mx = max(mx, l);
    mn = min(mn,r);
  }
  cout<<max(0,mn-mx+1)<<"\n";
}