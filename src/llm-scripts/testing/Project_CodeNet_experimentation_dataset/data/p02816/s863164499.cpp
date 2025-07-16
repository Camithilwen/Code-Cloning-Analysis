#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
using namespace std;
using Edge=pair<ll,ll>;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
  ll N;
  cin>>N;
  ll A[2*N],AA[N],B[2*N],BB[N];
  REP(i,N) cin>>AA[i];
  REP(i,N) cin>>BB[i];
  REP(i,N){
    A[i]=AA[i]^AA[(i+1)%N];
    A[N+i]=A[i];
  }
  REP(i,N){
    B[i]=BB[i]^BB[(i+1)%N];
    B[N+i]=B[i];
  }
  
  ll base=1007,P[N+1],HA=0,HB=0;
  P[0]=1;
  RREP(i,N) P[i]=P[i-1]*base%MOD;
  
  REP(i,N){
    HA+=A[i]*P[N-1-i]%MOD;
    HA%=MOD;
    HB+=B[i]*P[N-1-i]%MOD;
    HB%=MOD;
  }
  
  REP(i,N){
    if(HA==HB){
      ll X=AA[i]^BB[0];
      cout<<i<<" "<<X<<endl;
    }
    HA=HA*base%MOD;
    HA-=A[i]*P[N]%MOD;
    HA+=A[i+N];
    HA%=MOD;
    if(HA<0) HA+=MOD;
  }
  return 0;
}