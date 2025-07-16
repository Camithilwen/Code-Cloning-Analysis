#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define mp            make_pair
#define pb            push_back
template<class T1, class T2> inline void minup(T1& m, T2 x){ if(m>x) m=static_cast<T2>(x); }
template<class T1, class T2> inline void maxup(T1& m, T2 x){ if(m<x) m=static_cast<T2>(x); }

#define INF 1000000000
#define MOD 1000000007
#define EPS 1E-12

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAX_H = 12;
const int MAX_W = 12;
char m[MAX_H+1][MAX_W+1];


inline bool check(int x, int y){ return 0<=x&&x<MAX_H && 0<=y&&y<MAX_W; }

void dfs(int hx, int hy)
{
  rep(i, 4){
    int nx = hx + dx[i];
    int ny = hy + dy[i];

    if(!check(nx, ny)) continue;

    if(m[nx][ny] == '1'){
      m[nx][ny] = '0';
      dfs(nx, ny);
    }
  }
}

int main()
{

  while(true){
    rep(i, MAX_H) rep(j, MAX_W) if(!(cin >> m[i][j])) return 0;

    int res = 0;
    rep(i, MAX_H) rep(j, MAX_W) if(m[i][j] == '1'){
      res += 1;
      dfs(i, j);
    }

    cout << res << endl;
  }

  return 0;
}