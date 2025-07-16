#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n+2];
  a[0]=0;
  a[n+1]=0;
  rep(i,0,n) cin>>a[i+1];
  int sum[n+2];
  sum[0]=0;
  rep(i,0,n+1){
    sum[i+1]=sum[i]+abs(a[i+1]-a[i]);
  }
  
  int sum2[n+2];
  sum2[0]=0;
  rep(i,0,n+1){
    sum2[i+1]=sum2[i]+abs(a[n+1-i]-a[n-i]);
  }
  
  rep(i,1,n+1){
    cout<<sum[i-1]+sum2[n-i]+abs(a[i-1]-a[i+1])<<endl;
  }
}