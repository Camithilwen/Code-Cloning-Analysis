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

// $ cp-batch VotingJudges | diff VotingJudges.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address VotingJudges.cpp && ./a.out

/*

 6/28/2020

 9:50-

 */

const int MAX_N=1e6+1;
LL A[MAX_N],M;
int N,V,P;

bool ok(int m) {
  vector<LL> as(A,A+N);
  int v=0;
  as[m]+=M,++v;
  REP(i,P-1) if(v<V) as[i]+=M,++v;
  int i=N-1;
  for(; i>=0&&v<V&&as[i]<=as[m]-M; --i) {
    LL x=min(as[m]-as[i],(LL)M);
    if(x>0) as[i]+=x,++v;
  }
  LL rem=M*(V-v);
  //dump(p,rem,i,as[P-1],as[p]);
  //dumpc(as);
  while(rem>0&&i>P-2) {
    LL x=min(as[m]-as[i],rem);
    rem-=x,as[i]+=x;
    --i;
  }
  if(rem>0) return false;
  else return as[m]>=as[P-1];
}
void solve() {
  sort(A,A+N),reverse(A,A+N);
  //dumpC(A,A+N);
  int good=P-1,bad=N;
  while(abs(good-bad)>1) {
    int mid=(good+bad)/2;
    bool res=ok(mid);
    //dump(mid,res);
    (res?good:bad)=mid;
  }
  cout<<good+1<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;

  cin>>N>>M>>V>>P;
  REP(i,N) cin>>A[i];
  solve();

  return 0;
}
