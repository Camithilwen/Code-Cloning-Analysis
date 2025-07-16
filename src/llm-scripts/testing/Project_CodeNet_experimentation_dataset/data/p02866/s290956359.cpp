#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>
#define int ll

const ll MOD = 998244353;

ll cal(int a, int r){
  int p = 1;
  rep(i,r){
    p*=a;
    p%=MOD;
  }
  return p;
}

main(){
  int n;
  cin>>n;
  map<int,int> mp;
  int bottom=0;
  bool corner=0;
  rep(i,n){
    int d;
    cin>>d;
    if(i==0 && d!=0) corner=1;
    if(i!=0 && d==0) corner=1;
    mp[d]++;
    bottom=max(bottom,d);
  }
  if(corner) cout<<0<<endl;
  else{
    ll ans=1;
    for(int i = 1; i <= bottom; i++){
      if(mp[i]==0){
        cout<<0<<endl;
        return 0;
      }
      ans *= cal(mp[i-1],mp[i]);
      ans%=MOD;
    }
    cout<<ans<<endl;
  }
}

