#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int>> d(n,vector<int>(n));
  rep(i,m){
    int l,r;
    cin>>l>>r;
    l--; r--;
    d[n-l-1][r]++;
  }
  
  rep(i,n)for(int j=1;j<n;j++){
    d[i][j]+=d[i][j-1];
    if(i){
      if(d[i-1][j-1]!=d[i-1][j]){
        d[i][j]+=d[i-1][j]-d[i-1][j-1];
      }
    }
  }
  
  rep(i,q){
    int p,q;
    cin>>p>>q;
    p--; q--;
    cout<<d[n-p-1][q]<<endl;
  }
}