#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(){
  ll S;
  cin>>S;
  ll digit=0;
  ll d=S;
  while(d!=0){
    digit++;
    d/=10;
  }
  vector<ll> s(digit);
  rep(i,digit){
    s[i]=S%10;
    S/=10;
  }
  reverse(s.begin(),s.end());
  ll ans;
  ll cnt;
  ll cnt2;
  rep(i,digit-2){
    cnt=0;
    cnt2=0;
    cnt=s[i]*100+s[i+1]*10+s[i+2];
    cnt2=abs(753-cnt);
    if(i==0){
      ans=cnt2;
    }
    if(i>0){
      if(cnt2<ans){
        ans=cnt2;
      }
    }
  }
  cout<<ans<<endl;
}