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

// $ cp-batch 01Matrix | diff 01Matrix.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address 01Matrix.cpp && ./a.out

/*

 8/3/2020

 21:24-

 */

int H,W,A,B;

void solve() {
  REP(_,B) {
    REP(j,W) cout<<char('0'+(j<A));
    cout<<endl;
  }
  REP(_,H-B) {
    REP(j,W) cout<<char('0'+(j>=A));
    cout<<endl;
  }
}

bool ith(int mask, int i) { return (mask>>i)&1; }
void test() {
  set<II> ps;
  REP(mask, 1<<25) {
    VV<int> G(5,VI(5,0));
    REP(i,25) if(ith(mask,i)) {
      G[i/5][i%5]=1;
    }

    set<int> r,c;
    REP(i,5) {
      int cnt[2]={};
      REP(j,5) cnt[G[i][j]]++;
      r.emplace(min(cnt[0],cnt[1]));
    }
    REP(j,5) {
      int cnt[2]={};
      REP(i,5) cnt[G[i][j]]++;
      c.emplace(min(cnt[0],cnt[1]));
    }
    if(SZ(r)==1&&SZ(c)==1) {
      if(*r.begin()==2&&*c.begin()==1) {
        REP(i,5) dumpc(G[i]);
      }
      ps.emplace(*r.begin(), *c.begin());
    }
  }
  dumpc(ps);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;

  cin>>H>>W>>A>>B;
  solve();

  return 0;
}
