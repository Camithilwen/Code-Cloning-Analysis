#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template <typename T1, typename T2>
void chmax(T1 &a, const T2 &b) {
  if(a < b) a = b;
}

template <typename T1, typename T2>
void chmin(T1 &a, const T2 &b) {
  if(a > b) a = b;
}

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m, q; cin >> n >> m >> q;
  vector<string> s(n);
  for(int i=0;i<n;++i) {
    string tmp; cin >> tmp;
    s[i] = tmp;
  }

  vector<vector<int>> ver(n+1, vector<int>(m+1, 0));
  vector<vector<int>> tate(n+1, vector<int>(m+1, 0)), yoko(n+1, vector<int>(m+1, 0));
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      ver[i+1][j+1] = s[i][j] == '1';
    }
  }
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      ver[i+1][j+1] += ver[i+1][j] + ver[i][j+1] - ver[i][j];
    }
  }

  for(int i=0;i<n-1;++i) {
    for(int j=0;j<m;++j) {
      tate[i+1][j+1] = s[i][j] == '1' && s[i+1][j] == '1';
    }
  }
  for(int i=0;i<n-1;++i) {
    for(int j=0;j<m;++j) {
      tate[i+1][j+1] += tate[i+1][j] + tate[i][j+1] - tate[i][j];
    }
  }

  for(int i=0;i<n;++i) {
    for(int j=0;j<m-1;++j) {
      yoko[i+1][j+1] = s[i][j] == '1' && s[i][j+1] == '1';
    }
  }
  for(int i=0;i<n;++i) {
    for (int j = 0; j < m - 1; ++j) {
      yoko[i + 1][j + 1] += yoko[i + 1][j] + yoko[i][j + 1] - yoko[i][j];
    }
  }

  while(q--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    int tmpv = ver[x2][y2] - ver[x2][y1-1] - ver[x1-1][y2] + ver[x1-1][y1-1];
    int tmptate = tate[x2-1][y2] - tate[x2-1][y1-1] - tate[x1-1][y2] + tate[x1-1][y1-1];
    int tmpyoko = yoko[x2][y2-1] - yoko[x2][y1-1] - yoko[x1-1][y2-1] + yoko[x1-1][y1-1];

    cout << tmpv - tmptate - tmpyoko << endl;
  }
}
