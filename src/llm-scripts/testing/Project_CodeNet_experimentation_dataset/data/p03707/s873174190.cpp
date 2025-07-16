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
#define double long double
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
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
using namespace std;
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
  int N,M,Q;
  cin>>N>>M>>Q;
  string SS[N+1];
  
  int S[N+1][M+1];
  int C[N+1][M+1]; // 横に連続する1のマスの総数
  int R[N+1][M+1]; // 縦に連続する1のマスの総数
  int SUM[N+1][M+1]; // 存在する1のマスの総数
  
  for(int i=1; i<=N; ++i){
    cin>>SS[i];
    for(int j=1; j<=M; ++j){
      if(SS[i][j-1]=='0') S[i][j]=0;
      else S[i][j]=1;
    }
  }
  
  for(int i=0; i<=N; ++i){
    for(int j=0; j<=M; ++j){
      if(i*j==0){
        S[i][j]=0;
        C[i][j]=0;
        R[i][j]=0;
        SUM[i][j]=0;
      }
    }
  }
  
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=M; ++j){
      SUM[i][j]=SUM[i-1][j]+SUM[i][j-1]-SUM[i-1][j-1]+S[i][j];
      C[i][j]=C[i-1][j]+C[i][j-1]-C[i-1][j-1]+S[i][j];
      R[i][j]=R[i-1][j]+R[i][j-1]-R[i-1][j-1]+S[i][j];
      if(S[i][j]==1){
        if(S[i][j-1]==0) C[i][j]--;
        if(S[i-1][j]==0) R[i][j]--;
      }
    }
  }
  
  for(int i=1; i<=Q; ++i){
    int X,Y,XX,YY,ans=0;
    cin>>X>>Y>>XX>>YY;
    
    ans+=SUM[XX][YY]+SUM[X-1][Y-1]-SUM[X-1][YY]-SUM[XX][Y-1];
    ans-=R[XX][YY]+R[X][Y-1]-R[XX][Y-1]-R[X][YY];
    ans-=C[XX][YY]+C[X-1][Y]-C[X-1][YY]-C[XX][Y];
    
    co(ans);
  }
  
  return 0;
}