#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

vector<ll> vec;
vector<ll> vec2;

void init(){
  ll x = 1;
  ll x2 = 1;
  while(x<10000000000){
    vec.push_back(x);
    x2*=4;
    x+=x2;
  }
  ll y = 0;
  ll y2 = 2;
  while(y>-10000000000){
    vec2.push_back(y);
    y-=y2;
    y2*=4;
  }
}

vector<ll> ans(33,0);

void solve(ll N){
  if(N==1){
    ans.at(0)=1;
  }else if(N==0){
    ans.at(0)=0;
  }else if(N>1){
    REP(i,vec.size()){
      if(N<=vec.at(i)){
        ans.at(i*2)=1;
        solve(N-pow(2,i*2));
        break;
      }
    }
  }else if(N<0){
    REP(i,vec2.size()){
      if(vec2.at(i)<=N){
        ans.at(i*2-1)=1;
        solve(N+pow(2,i*2-1));
        break;
      }
    }
  }
}

int main()
{
  ll N;
  cin >> N;
  init();
  solve(N);

  int flag = 0;


  REPR(i,32){
    if(ans.at(i)==1&&flag==0){
      flag=1;
    }
    if(flag==1){
      cout << ans.at(i);
    }
  }
  if(flag==0){
    cout << 0;
  }
  cout << endl;
}