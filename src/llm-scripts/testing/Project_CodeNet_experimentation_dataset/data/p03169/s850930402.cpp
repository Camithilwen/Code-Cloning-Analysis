#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
const double EPS = 1e-9;
const long long MOD=1e9+7;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
ll n; 
double dfs(vvvd &dp, ll n1, ll n2, ll n3){
  if(n1==0 && n2==0 && n3==0) return 0.0;
  if(dp[n1][n2][n3] >= 0.0){
    return dp[n1][n2][n3];
  }
  double expect = (double)n / (n1+n2+n3);
  if(n1 > 0){
    expect += dfs(dp, n1-1, n2, n3) * (double)n1/(n1+n2+n3);
  }
  if(n2 > 0){
    expect += dfs(dp, n1+1, n2-1, n3) * (double)n2/(n1+n2+n3);
  }
  if(n3 > 0){
    expect += dfs(dp, n1, n2+1, n3-1) * (double)n3/(n1+n2+n3);
  }
  return dp[n1][n2][n3] = expect;
}
int main(){
  cin>>n;
  vll a(n); rep(i,n) cin>>a[i];
  double p=1.0/n;
  ll n1,n2,n3; n1=n2=n3=0;
  rep(i,n){
    if(a[i]==1) n1++;
    else if(a[i]==2) n2++;
    else if(a[i]==3) n3++;
  }
  vvvd dp(n+1,vvd(n+1,vd(n+1,-1)));
  double ans = dfs(dp,n1,n2,n3);
  cout<< fixed << setprecision(10)<< ans<<endl;
}