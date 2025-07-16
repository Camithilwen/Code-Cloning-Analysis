#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,m,x,y;
  cin>>n>>m>>x>>y;
  int cnt;
  int sum;
  string ans="War";
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  vector<int> b(m);
  rep(i,m){
    cin>>b[i];
  }
  for(int i=x+1;i<y;i++){
    cnt=0;
    for(int j=0;j<n;j++){
      if(i>a[j]) cnt++;
    }
    sum=0;
    if(cnt==n){
      for(int j=0;j<m;j++){
        if(i<=b[j]) sum++;
      }
    }
    if(sum==m) ans="No War";
  }
  cout<<ans<<endl;
}