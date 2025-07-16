#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,m;
  cin>>n>>m;
  int ans;
  for(int i = m/n; i >= 1; i--){
    if((m-n*i)%i==0) {ans=i; break;}
  }
  cout<<ans<<endl;
}
