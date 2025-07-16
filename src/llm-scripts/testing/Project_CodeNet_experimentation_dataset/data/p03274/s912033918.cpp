#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll i,sum=0,mini=1e9+7;
  for(i=0;i<=n-k;i++){
    sum=a.at(i+k-1)-a.at(i);
    if(a.at(i+k-1)>0 && a.at(i)<0){
      ll p=min(a.at(i+k-1),abs(a.at(i)));
      sum+=p;
    }else{
      sum=max(abs(a.at(i+k-1)),abs(a.at(i)));
    }
    mini=min(mini,sum);
  }
  cout << mini;
}