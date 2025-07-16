#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;

ll rev(ll x,int n){
  ll ret=0;
  repeat(i,n){
    ret *= 10;
    ret += x%10;
    x /= 10;
  }
  return ret;
}

ll dfs(ll D,int n,int cnt,int dig,ll N){
  if(cnt>=n/2){
    return rev(N,n)==N+D? N:-1;
  }
  if(cnt>=0){
    if(dig>=0){
      ll d=dig;
      repeat(c,n-1-cnt) d*=10;
      N += d;
    }else{
      ll d=-dig;
      repeat(c,cnt) d*=10;
      N += d;
    }
  }
  ll ret = -1;
  for(int i=-9;i<=(cnt<0? 0:9);i++){
    ret = max(ret,dfs(D,n,cnt+1,i,N));
  }
  return ret;
}

int main(){
  ll D;cin >> D;
  if(D%9!=0){
    cout << 0 << endl;
    return 0;
  }
  int num10=0;
  while(D%10==0){
    D/=10;
    num10++;
  }
  string Dstr=to_string(D);
  int n = Dstr.length();
  //debug(n);
  ll ans = 0;
  repeat(d,7){
    int m = n+d;
    ll N=0;
    if(d>0){
      if(D%10!=9)break;
      if(d>1 && D%100!=89)break;
      repeat(c,d-1){
        N*=10;
        N+=9;
      }
      repeat(c,n){
        N*=10;
      }
      N+=1;
    }
    //debug(N);
    N = dfs(D,m,d-1,0,N);
    debug(N);
    if(N>0){
      string Nstr = to_string(N);
      while(Nstr.length()<m) Nstr = "0"+Nstr;
      ll a=1;
      repeat(j,(m+1)/2){
        int mi=Nstr[j]-'0',ma=Nstr[m-1-j]-'0';
        if(mi>ma)swap(mi,ma);
        a *= j==0? 9-ma+ (num10>0):10-(ma-mi);
      }
      debug(a);
      ans += a;
    }
  }
  if(ans>0&&num10>0){
    repeat(c,num10-1)ans *= 10;
    ans *= 9;
  }
  cout << ans << endl;
  return 0;
}
