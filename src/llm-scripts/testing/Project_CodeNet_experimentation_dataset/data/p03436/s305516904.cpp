#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = 1; i <= (int)(n); i++)
#define drep(i, n) for(int i = (n)-1; i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define dup(x,y) (((x)+(y)-1)/(y))
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// Mod int
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
//

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vvi dist(h, vi(w, INF));
  if (s[0][0] == '#') {cout<<-1<<endl; return 0;};
  vvi used(h, vi(w, 0));
  dist[0][0] = 0;
  used[0][0] = 1;
  queue<P> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    int d = dist[i][j];
    rep(dir, 4) {
      int ni = i + di[dir], nj = j + dj[dir];
      if (ni<0||nj<0||ni>=h||nj>=w) continue;
      if (s[ni][nj] == '#') continue;
      if (used[ni][nj]) continue;
      dist[ni][nj] = d + 1;
      used[ni][nj]++;
      q.emplace(ni, nj);
    }   
  }
  if (dist[h-1][w-1] == INF) {cout << -1 << endl; return 0;};
  int ans = h*w;
  rep(i, h) rep(j, w) if (s[i][j] == '#') ans--;
  ans -= dist[h-1][w-1] + 1;
  cout << ans << endl;
}