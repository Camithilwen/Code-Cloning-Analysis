#include<bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
//using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  string s;
  cin >> s;

  ll a=s[0]-'0',b=s[1]-'0',c=s[2]-'0',d=s[3]-'0';

  for(ll i=-1;i<2;i+=2){
    for(ll j=-1;j<2;j+=2){
      for(ll k=-1;k<2;k+=2){
        if(a+b*i+c*j+d*k==7){
          string t;
          t=to_string(a);
          char e;
          if(i<0)e='-';
          else e='+';
          t+=e;
          t+=to_string(b);
          if(j<0)e='-';
          else e='+';
          t+=e;
          t+=to_string(c);
          if(k<0)e='-';
          else e='+';
          t+=e;
          t+=to_string(d);
          t+="=7";
          cout << t << endl;          
          return 0;
        }
      }
    }
  }

  return 0;
}