#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),ev(100001),od(100001);
  rep(i,n){
    cin >> a.at(i);
    if(i%2==0){
      od.at(a.at(i))++;
    }else{
      ev.at(a.at(i))++;
    }
  }
  ll maxiev=0,maxiod=0,soeev,soeod;
  rep(i,100001){
    if(maxiev<ev.at(i)){
      maxiev=ev.at(i);
      soeev=i;
    }
    if(maxiod<od.at(i)){
      maxiod=od.at(i);
      soeod=i;
    }
  }
  if(soeev!=soeod){
    cout << n/2-maxiev+n/2-maxiod;
  }else{
    if(maxiev<maxiod){
      ll q=0;
      rep(i,100001){
        if(soeev!=i && q<ev.at(i)){
          q=ev.at(i);
        }
      }
      cout << n/2-maxiod+n/2-q;
    }else if(maxiev>maxiod){
      ll q=0;
      rep(i,100001){
        if(soeod!=i && q<od.at(i)){
          q=od.at(i);
        }
      }
      cout << n/2-maxiev+n/2-q;
    }else{
      ll p=0,q=0;
      rep(i,100001){
        if(soeev!=i && q<ev.at(i)){
          q=ev.at(i);
        }
      }
      rep(i,100001){
        if(soeod!=i && p<od.at(i)){
          p=od.at(i);
        }
      }
      ll ans=max(p,q);
      cout <<n/2-ans+n/2-maxiod;
    }
  }
}
    