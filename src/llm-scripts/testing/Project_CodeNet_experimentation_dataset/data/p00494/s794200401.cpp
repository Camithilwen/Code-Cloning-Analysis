#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
//C++11
#if __cplusplus == 201103L
#include <tuple>
#endif

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  string s;
  map<char, int> m;
  m['J'] = 0;
  m['O'] = 1;
  m['I'] = 2;
  while(cin>>s){
    s = "I" + s;
    int N = s.size();
    int cnt[3]={};
    int ans = 0;
    for(int i = 1; i < N; i++){
      int n = m[s[i]];
      int b = m[s[i-1]];
      if(n < b){
        REP(i, 3) cnt[i] = 0;
        if(n == 0) cnt[0]++;
      }else{
        cnt[n]++;
        if(cnt[0]>=cnt[1]&&cnt[1]==cnt[2]) ans = max(ans, cnt[1]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}