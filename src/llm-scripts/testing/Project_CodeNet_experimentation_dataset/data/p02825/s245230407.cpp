#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<vector<string>> s = {
  {
    "bcaa",
    "bcdd",
    "eegh",
    "ffgh"
  }, {
    "..abc",
    "..abc",
    "ddgee",
    "ffg.j",
    "hhiij"
  }, {
    "...abc",
    "...abc",
    "def...",
    "def...",
    "gghhii",
    "jjkkll"
  }, {
    "i..ll.a",
    "i..d..a",
    "..gd.nn",
    "..g..mj",
    "hh...mj",
    "effbb..",
    "ekk.cc."
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n < 3) {
    cout << -1 << endl;
    return 0;
  }
  if (n == 3) {
    cout << "..a\n..a\nbb.\n";
    return 0;
  }
  vector<vector<char>> grid(n, vector<char>(n, '.'));
  for (int i = 0; i+4 < n; i+=4) {
    rep(j, 4) rep(k, 4)
      grid[i+j][i+k] = s[0][j][k];
  }
  int rem = n%4;
  rep(i, rem+4) rep(j, rem+4)
    grid[n-rem-4+i][n-rem-4+j] = s[rem][i][j];
  rep(i, n) {
    rep(j, n)
      cout << grid[i][j];
    cout << '\n';
  }
  return 0;
}



/*
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

vector<vector<char>> grid;
int n;

bool check3() {
  rep(i, n) {
    int num = 0;
    char prev = '.';
    rep(j, n) {
      if (grid[i][j] != prev) {
        if (grid[i][j] != '.')
          num++;
        prev = grid[i][j];
      }
    }
    if (num != 3)
      return false;
  }
  rep(j, n) {
    int num = 0;
    char prev = '.';
    rep(i, n) {
      if (grid[i][j] != prev) {
        if (grid[i][j] != '.')
          num++;
        prev = grid[i][j];
      }
    }
    if (num != 3)
      return false;
  }
  return true;
}

void dfs(int now, int c) {
  if (now == n*n) {
    if (!check3())
      return;
    rep(i, n) {
      rep(j, n)
        cout << grid[i][j];
      cout << '\n';
    }
    exit(0);
  }
  int x = now/n, y = now%n;
  dfs(now+1, c);
  if (x > 0 && grid[x-1][y] == '.') {
    grid[x-1][y] = grid[x][y] = 'a'+c;
    dfs(now+1, (c+1)%26);
    grid[x-1][y] = grid[x][y] = '.';
  }
  if (y > 0 && grid[x][y-1] == '.') {
    grid[x][y-1] = grid[x][y] = 'a'+c;
    dfs(now+1, (c+1)%26);
    grid[x][y-1] = grid[x][y] = '.';
  }
}

int main() {
  cin >> n;
  grid.resize(n, vector<char>(n, '.'));
  if (n < 7)
    dfs(0, 0);
  else {
    random_device rnd;
    mt19937 mt(rnd());
    while (true) {
      rep(i, n) rep(j, n) grid[i][j] = '.';
      int cnt = 0, c = 0;
      int lim = 3*n*2/3; //1つのドミノは行と列合わせて3箇所を+1する->クオリティの総和/3=ドミノの数
      while (cnt < lim) {
        int x = mt()%n, y = mt()%n, d = mt()%2;
        if (grid[x][y] != '.')
          continue;
        if (d && x+1 < n && grid[x+1][y] == '.') {
          grid[x][y] = grid[x+1][y] = 'a'+c;
          c = (c+1)%26;
          cnt++;
        } else if (y+1 < n && grid[x][y+1] == '.') {
          grid[x][y] = grid[x][y+1] = 'a'+c;
          c = (c+1)%26;
          cnt++;
        }
      }
      if (check3()) {
        rep(i, n) {
          rep(j, n)
            cout << grid[i][j];
          cout << '\n';
        }
        break;
      }
    }
  }
  return 0;
}
*/