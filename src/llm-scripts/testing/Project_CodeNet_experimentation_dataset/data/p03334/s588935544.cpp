#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

int nextInt() { int x; scanf("%d", &x); return x;}

const int MAX_N = 610;
int result1[MAX_N][MAX_N];
int result2[MAX_N][MAX_N];

void dfs(const int N, int r, int c, const vector<pair<int,int>>& d, int result[MAX_N][MAX_N], const int val) {
  result[r][c] = val;
  for (auto p : d) {
    const int nr = r + p.first;
    const int nc = c + p.second;
    if (0 <= nr && nr < N && 0 <= nc && nc < N && result[nr][nc] == -1) {
      dfs(N, nr, nc, d, result, 1-val);
    }
  }
}

void solve(int N, int D, int result[MAX_N][MAX_N]) {

  vector<pair<int,int>> d;
  REP(r, N) REP(c, N) {
    if (r * r + c * c == D) {
      d.push_back({r, c});
      if (r > 0) d.push_back({-r, c});
      if (c > 0) d.push_back({r, -c});
      if (r > 0 && c > 0) d.push_back({-r, -c});
    }
  }

  REP(r, N) REP(c, N) if (result[r][c] == -1) {
    dfs(N, r, c, d, result, 0);
  }

  return;
  
}

int ans[MAX_N][MAX_N];

int main2() {
  int N = nextInt();
  int D1 = nextInt();
  int D2 = nextInt();

  CLR(result1, -1);
  solve(2*N, D1, result1);

  CLR(result2, -1);
  solve(2*N, D2, result2);

  vector<int> sz(4);
  REP(r, 2*N) REP(c, 2*N) {
    ans[r][c] = result1[r][c] * 2 + result2[r][c];
    sz[ ans[r][c] ]++;
  }

  int cnt = 0;
  int mai = distance(sz.begin(), max_element(ALL(sz)));
  REP(r, 2*N) REP(c, 2*N) {
    if (ans[r][c] == mai && cnt < N*N) {
      printf("%d %d\n", r, c);
      cnt++;
    }
  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
