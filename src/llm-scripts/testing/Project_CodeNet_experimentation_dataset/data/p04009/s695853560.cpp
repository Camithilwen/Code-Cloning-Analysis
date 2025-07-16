/// {{{ Author: Wang, Yen-Jen
// include
#include <bits/stdc++.h>

// using
using namespace std;

// types
typedef long long ll;
typedef pair<int,int> pii;

// macro
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin() , (x).end()
#define REP(i , n) for(int i = 0; i < int(n); i++)
#define REP1(i , a , b) for(int i = a; i <= int(b); i++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LC o<<1 , l , m
#define RC o<<1|1 , m + 1 , r
#define MS(x , v) memset(x , (v) , sizeof(x))

// input
inline bool SR(int &x) {
  return scanf("%d",&x) == 1;
}

inline bool SR(ll &x) {
  return scanf("%lld",&x) == 1;
}

inline bool SR(double &x) {
  return scanf("%lf",&x) == 1;
}

inline bool SR(char *s) {
  return scanf("%s",s) == 1;
}

inline bool RI() {
  return true;
}

template<typename I , typename... T> inline bool RI(I &x , T&... tail) {
  return SR(x) && RI(tail...);
}

// output
inline void SP(const int x) {
  printf("%d",x);
}

inline void SP(const ll x) {
  printf("%lld",x);
}

inline void SP(const double x) {
  printf("%.16lf",x);
}

inline void SP(const char *s) {
  printf("%s",s);
}

inline void PL() {
  puts("");
}

template<typename I , typename... T> inline void PL(const I x , const T... tail) {
  SP(x);
  if(sizeof...(tail)) putchar(' ');
  PL(tail...);
}

// debug
#define WangYenJen

#ifdef WangYenJen
template<typename I> void _DOING(const char *s , I&& x) {
  cerr << s << " = " << x << endl;
}

template<typename I , typename... T> void _DOING(const char *s , I&& x , T&&... tail) {
  int c = 0;
  while(*s != ',' || c != 0) {
    if(*s == '(' || *s == '[' || *s == '{') c++;
    if(*s == ')' || *s == ']' || *s == '}') c--;
    cerr << *s++;
  }
  cerr << " = " << x << " , ";
  _DOING(s + 1 , tail...);
}

#define DEBUG(...) \
do {\
  fprintf(stderr , "%s: Line %d - ",__PRETTY_FUNCTION__,__LINE__);\
  _DOING(#__VA_ARGS__ , __VA_ARGS__);\
} while(0);

#else
#define DEBUG(...)

#endif

// constant number
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3fll;

// random function
inline int RAND() {
  static int x = 880301;
  return (x = x * 0xdefaced + 1) % 0x7fffffff;
}
/// }}}

const int MAX_N = 100 + 3;

int n, m;
int sx, sy;
char str[MAX_N];
int sum[MAX_N][MAX_N];
short dp[MAX_N][MAX_N][MAX_N][MAX_N];

int get_sum(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  else return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

int main() {
  RI(n, m);
  REP1(i, 1, n) {
    SR(str + 1);
    REP1(j, 1, m) {
      if (str[j] == 'E') sx = i, sy = j;
      else if (str[j] == 'o') sum[i][j] = 1;
      sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int ans = 0;
  REP1(i, 0, sx - 1) {
    REP1(j, 0, sy - 1) {
      REP1(x, 0, n - sx) {
        REP1(y, 0, m - sy) {
          ans = max(ans, (int)dp[i][j][x][y]);
          int v = 0;
          if (i + x + 1 <= sx - 1) v = get_sum(sx - i - 2, max(sy - j - 1, y), sx - i - 1, min(sy + y, m - j));
          else v = 0;
          dp[i + 1][j][x][y] = max((int)dp[i + 1][j][x][y], dp[i][j][x][y] + v);
          if (i + x + 1 <= n - sx) v = get_sum(sx + x, max(sy - j - 1, y), sx + x + 1, min(sy + y, m - j));
          else v = 0;
          dp[i][j][x + 1][y] = max((int)dp[i][j][x + 1][y], dp[i][j][x][y] + v);
          if (j + y + 1 <= sy - 1) v = get_sum(max(sx - i - 1, x), sy - j - 2, min(sx + x, n - i), sy - j - 1);
          else v = 0;
          dp[i][j + 1][x][y] = max((int)dp[i][j + 1][x][y], dp[i][j][x][y] + v);
          if (j + y + 1 <= m - sy) v = get_sum(max(sx - i - 1, x), sy + y, min(sx + x, n - i), sy + y + 1);
          else v = 0;
          dp[i][j][x][y + 1] = max((int)dp[i][j][x][y + 1], dp[i][j][x][y] + v);
        }
      }
    }
  }
  PL(ans);
  return 0;
}
