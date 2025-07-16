#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


int N;
vector<string> field(8, "........");

bool check(int x,int y){
  // 攻撃されるならtrue
  bool ng = false;
  for (int i=0; i<8; i++) if (field[i][y] == 'Q') ng = true;
  for (int j=0; j<8; j++) if (field[x][j] == 'Q') ng = true;
  int a = x, b = y;
  while (a >= 0 && b >= 0) if (field[a--][b--] == 'Q') ng = true;
  a = x, b = y;
  while (a < 8 && b < 8) if (field[a++][b++] == 'Q') ng = true;
  a = x, b = y;
  while (a >= 0 && b < 8) if (field[a--][b++] == 'Q') ng = true;
  a = x, b = y;
  while (a < 8 && b >= 0) if (field[a++][b--] == 'Q') ng = true;
  return ng;
}

void rec(int row){
  if (row == 8){
    rep(i, 8) cout <<field[i] <<endl;
    return;
  }
  // 各行について考える
  bool ok = false; rep(i, 8) ok = ok | (field.at(row).at(i) == 'Q');
  if (ok) rec(row+1);
  // Queenが置かれていなかった場合、置けるところに置く
  rep(j, 8){
    if (check(row, j)) continue;
    field[row][j] = 'Q';
    rec(row+1);
    field[row][j] = '.';
  }
}

int main() {
  cin >>N;
  rep(q, N){
    int x,y; cin >>x >>y;
    field[x][y] = 'Q';
  }
  rec(0);
}
