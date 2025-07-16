#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1001001001;

int dp[400][400];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int h, w;
vector<vector<bool>> used(400, vector<bool>(400));
ll black = 0, white = 0;

void dfs(int x, int y, vector<string> &s) {
  if (used[x][y]) return;
  used[x][y] = true;
  if (s[x][y] == '.') white++;
  else black++;

  char cur = s[x][y];
  rep(i, 4) {
    int nx = dx[i] + x;
    int ny = dy[i] + y;
    if (0 <= nx && nx < h && 0 <= ny && ny < w) {
      char next = s[nx][ny];
      if (next != cur) {
        dfs(nx, ny, s);
      }
    }
  }
}

int main() {
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll ans = 0;
  rep(i, h) rep(j, w) {
    black = white = 0;
    dfs(i, j, s);
    ans += black * white;
  }

  cout << ans << endl;
}