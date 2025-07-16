#include <bits/stdc++.h>
using namespace std;
// type alias
typedef long long LL;
typedef pair<int,int> II;
typedef tuple<int,int,int> III;
typedef vector<int> VI;
typedef vector<string> VS;
typedef unordered_map<int,int> MAPII;
typedef unordered_set<int> SETI;
template<class T> using VV=vector<vector<T>>;
// minmax
template<class T> inline T SMIN(T& a, const T b) { return a=(a>b)?b:a; }
template<class T> inline T SMAX(T& a, const T b) { return a=(a<b)?b:a; }
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// collection
#define ALL(c) (c).begin(),(c).end()
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// stdout
#define println(args...) fprintf(stdout, ##args),putchar('\n');
// debug cerr
template<class Iter> void __kumaerrc(Iter begin, Iter end) { for(; begin!=end; ++begin) { cerr<<*begin<<','; } cerr<<endl; }
void __kumaerr(istream_iterator<string> it) { (void)it; cerr<<endl; }
template<typename T, typename... Args> void __kumaerr(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<"="<<a<<", ",__kumaerr(++it, args...); }
template<typename S, typename T> std::ostream& operator<<(std::ostream& _os, const std::pair<S,T>& _p) { return _os<<"{"<<_p.first<<','<<_p.second<<"}"; }
#define __KUMATRACE__ true
#ifdef __KUMATRACE__
#define dump(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); __kumaerr(_it, args); }
#define dumpc(ar) { cerr<<#ar<<": "; FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }
#define dumpC(beg,end) { cerr<<"~"<<#end<<": "; __kumaerrc(beg,end); }
#else
#define dump(args...)
#define dumpc(ar)
#define dumpC(beg,end)
#endif

// $ cp-batch FlipAndRectangles | diff FlipAndRectangles.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address FlipAndRectangles.cpp && ./a.out

/*
 
 11/9/2019
 
 16:34-16:41 give up
 
 11/10/2019
 
 15:40- read editorial
 
 http://kmjp.hatenablog.jp/entry/2017/08/24/0930
 https://youtu.be/xRYReB8pc2E?t=2803
 
 */

const int MAX_N=2000+1;
string G[MAX_N];
int H,W;

int cum[MAX_N][MAX_N];
void solve() {
  REP(i,H-1) {
    cum[i][W-1]=1;
    for(int j=W-2; j>=0; --j) {
      int cur=G[i][j]==G[i+1][j],r=G[i][j+1]==G[i+1][j+1];
      if(cur==r) cum[i][j]=cum[i][j+1];
      cum[i][j]+=1;
    }
//    dumpC(cum[i],cum[i]+W);
  }
  
  int res=max(H,W);
  REP(j,W) {
    stack<II> S; S.emplace(0,0);
    REP(i,H) {
      int a=cum[i][j],b=i;
      while(SZ(S)&&S.top().first>=a) {
        auto p=S.top(); S.pop();
        int x=i-p.second+1,y=p.first;
        SMAX(res,x*y);
        b=p.second;
      }
      S.emplace(a,b);
    }
  }
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;
  
  cin>>H>>W;
  REP(i,H) cin>>G[i];
  solve();
  
  return 0;
}
