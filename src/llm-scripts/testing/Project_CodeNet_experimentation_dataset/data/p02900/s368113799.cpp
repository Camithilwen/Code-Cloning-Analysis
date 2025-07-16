#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll a,ll b){
  while(b>0){
    ll r=a%b;
    a=b;
    b=r;
  }
  return a;
}   
int main(){
  ll a,b;
  cin >> a >> b;
  ll p=gcd(a,b);
  ll i;
  ll cp=p;
  vector<ll> ans(2000);
  ans.at(0)=1;
  ll j=1;
  for(i=2;i*i<=p;i++){
    bool is=false;
    while(cp%i==0){
      cp/=i;
      is=true;
    }
    if(is){
      ans.at(j)=i;
      j++;
    }
  }
  if(cp!=1){
    ans.at(j)=cp;
  }
  rep(i,2000){
    if(ans.at(i)==0){
      break;
    }
    
  }
  rep(i,2000){
    if(ans.at(i)==0){
      cout << i;
      return 0;
    }
  }
}