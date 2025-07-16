#include<bits/stdc++.h>
#define INF 10000000000ll
#define ll long long
using namespace std;
signed main(){
  ll n,m,x,y,a,b;
  cin>>n>>m>>x>>y;
  for(int i=0;i<n;i++){
    cin>>a;
    x = max(a,x);
  }
  for(int i=0;i<m;i++){
    cin>>b;
    y = min(y,b);
  }
  if(y > x){
    cout<<"No War\n";
  }else{
    cout<<"War\n";
  }
  return 0;
}