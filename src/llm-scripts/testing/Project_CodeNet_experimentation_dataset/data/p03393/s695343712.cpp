#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
int main(){
  string S;
  cin>>S;
  if(S=="zyxwvutsrqponmlkjihgfedcba"){cout<<-1<<endl;}
  else if(S.size()==26){
    ll maxcharacter=S.at(25);
    ll rock;
    for(ll i=0;i<25;i++){
      if(S.at(24-i)<maxcharacter){
        for(ll j=0;j<24-i;j++){cout<<S.at(j);}
        rock=24-i;
        unordered_map<ll,ll> mp;
        for(ll i=0;i<rock;i++){
          mp[S.at(i)]++;
        }
        char start=S.at(rock)+1;
        while(mp[start]>0){start++;}
        cout<<start<<endl;
        return 0;
      }
      else{maxcharacter=S.at(24-i);}
    }
  }
  else{
    unordered_map<ll,ll> mp;
    for(ll i=0;i<(ll)S.size();i++){
      mp[S.at(i)]++;
    }
    cout<<S;
    if(mp['a']==0){cout<<"a"<<endl;return 0;}
    if(mp['b']==0){cout<<"b"<<endl;return 0;}
    if(mp['c']==0){cout<<"c"<<endl;return 0;}
    if(mp['d']==0){cout<<"d"<<endl;return 0;}
    if(mp['e']==0){cout<<"e"<<endl;return 0;}
    if(mp['f']==0){cout<<"f"<<endl;return 0;}
    if(mp['g']==0){cout<<"g"<<endl;return 0;}
    if(mp['h']==0){cout<<"h"<<endl;return 0;}
    if(mp['i']==0){cout<<"i"<<endl;return 0;}
    if(mp['j']==0){cout<<"j"<<endl;return 0;}
    if(mp['k']==0){cout<<"k"<<endl;return 0;}
    if(mp['l']==0){cout<<"l"<<endl;return 0;}
    if(mp['m']==0){cout<<"m"<<endl;return 0;}
    if(mp['n']==0){cout<<"n"<<endl;return 0;}
    if(mp['o']==0){cout<<"o"<<endl;return 0;}
    if(mp['p']==0){cout<<"p"<<endl;return 0;}
    if(mp['q']==0){cout<<"q"<<endl;return 0;}
    if(mp['r']==0){cout<<"r"<<endl;return 0;}
    if(mp['s']==0){cout<<"s"<<endl;return 0;}
    if(mp['t']==0){cout<<"u"<<endl;return 0;}
    if(mp['u']==0){cout<<"u"<<endl;return 0;}
    if(mp['v']==0){cout<<"v"<<endl;return 0;}
    if(mp['w']==0){cout<<"w"<<endl;return 0;}
    if(mp['x']==0){cout<<"x"<<endl;return 0;}
    if(mp['y']==0){cout<<"y"<<endl;return 0;}
    if(mp['z']==0){cout<<"z"<<endl;return 0;}
  }
}