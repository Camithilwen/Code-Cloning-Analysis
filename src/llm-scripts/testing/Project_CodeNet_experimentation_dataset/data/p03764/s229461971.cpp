#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
signed main(){
  int n,m,x1,y1;
  cin>>n>>m>>x1;
  int ans1=0,ans2=0;
  for(int i=0;i<n-1;i++){
    int x2;
    cin>>x2;
    ans1=(ans1+(x2-x1)*(i+1)%mod*(n-1-i)%mod)%mod;
    x1=x2;
  }
  cin>>y1;
  for(int i=0;i<m-1;i++){
    int y2;
    cin>>y2;
    ans2=(ans2+(y2-y1)*(i+1)%mod*(m-1-i)%mod)%mod;
    y1=y2;
  }
  cout<<ans1*ans2%mod;
}