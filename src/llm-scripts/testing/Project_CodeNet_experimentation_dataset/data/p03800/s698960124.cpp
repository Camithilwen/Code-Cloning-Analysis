//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
#define mp make_pair
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

ll n;
st s;
vc a;
bool b;

void srch(ll z,ll f){
  if(z==0){
    a[0]='S';
  }
  else{
    a[0]='W';
  }
  if(f==0){
    a[1]='S';
  }
  else{
    a[1]='W';
  }
  FOR(i,1,n-1){
    if((a[i]=='S'&&s[i]=='o')||(a[i]=='W'&&s[i]=='x')){
      a[i+1]=a[i-1];
    }
    else{
      if(a[i-1]=='W'){
        a[i+1]='S';
      }
      else{
        a[i+1]='W';
      }
    }
  }
  b=true;
  rep(i,2){
    ll cnt=0;
    if(a[(n-1+i)%n]=='W'){
      cnt++;
    }
    if(s[(n-1+i)%n]=='x'){
      cnt++;
    }
    if(a[(n-2+i)%n]!=a[i%n]){
      cnt++;
    }
    if(cnt%2==1){
      b=false;
    }
  }
}
int main(){
  cin >> n >> s;
  a.resize(n);
  b=false;
  srch(0,0);
  if(b){
    rep(i,n){
      cout << a[i];
    }
    return 0;
  }
  srch(0,1);
  if(b){
    rep(i,n){
      cout << a[i];
    }
    return 0;
  }
  srch(1,0);
  if(b){
    rep(i,n){
      cout << a[i];
    }
    return 0;
  }
  srch(1,1);
  if(b){
    rep(i,n){
      cout << a[i];
    }
    return 0;
  }
  cout << -1 << endl;
}