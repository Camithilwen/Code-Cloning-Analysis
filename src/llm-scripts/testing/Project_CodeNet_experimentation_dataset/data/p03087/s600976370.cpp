#include<bits/stdc++.h>
using namespace std;

struct CumulativeSum {
  vector<long long> csum;
  template<typename T>
  CumulativeSum(vector<T> input) : csum(input.size() + 1, 0) {
    for(int i = 0; i < (int)input.size(); i++) csum[i+1] = csum[i] + input[i];
  }
  long long query(int l, int r) { /* 0-indexed, inclusive */ return csum[r+1] - csum[l]; }
};

struct CumulativeSum2D {
  vector<vector<long long>> csum;
  template<typename T>
  CumulativeSum2D(vector<vector<T>> input) : csum(input.size() + 1, vector<long long>(input[0].size() + 1, 0)) {
    for(int i = 0; i < (int)input.size(); i++) for(int j = 0; j < (int)input[i].size(); j++)
      csum[i+1][j+1] += csum[i+1][j] + csum[i][j+1] - csum[i][j] + input[i][j];
  }
  CumulativeSum2D(vector<string> input, char target) : csum(input.size() + 1, vector<long long>(input[0].size() + 1, 0)) {
    for(int i = 0; i < (int)input.size(); i++) for(int j = 0; j < (int)input[i].size(); j++)
      csum[i+1][j+1] += csum[i+1][j] + csum[i][j+1] - csum[i][j] + (input[i][j]==target);
  }
  long long query(int y_top, int x_left, int y_bottom, int x_right) { /* 0-indexed, inclusive */
    return csum[y_bottom+1][x_right+1] - csum[y_top][x_right+1] - csum[y_bottom+1][x_left] + csum[y_top][x_left];
  }
};

signed main() {
#if 1 // https://atcoder.jp/contests/abc122/tasks/abc122_c
  int n,q; cin >> n >> q;
  string s; cin >> s;
  vector<bool> ac(n);
  for(int i=0; i<n-1; ++i) ac[i] = s[i] == 'A' && s[i+1] == 'C';
  CumulativeSum cs(ac);
  while(q--) {
    int l,r; cin >> l >> r; --l, r-=2;
    cout << cs.query(l,r) << endl;
  }
#elif 1 // https://atcoder.jp/contests/abc005/tasks/abc005_4
  int n; cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin >> grid[i][j];
  CumulativeSum2D cs(grid);

  vector<int> ans(n*n+1);
  for(int y1=0; y1<n; ++y1) for(int x1=0; x1<n; ++x1) for(int y2=y1; y2<n; ++y2) for(int x2=x1; x2<n; ++x2) {
    int w = x2 - x1 + 1, h = y2 - y1 + 1;
    ans[w*h] = max(ans[w*h], (int)cs.query(y1,x1,y2,x2));
  }
  for(int i=1; i<= n*n; ++i) ans[i] = max(ans[i], ans[i-1]);

  int q; cin >> q;
  while(q--) {
    int p; cin >> p;
    cout << ans[p] << endl;
  }
#else // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
  int n,m,k; cin >> m >> n >> k;
  vector<string> grid(m);
  for(int i=0; i<m; ++i) cin >> grid[i];

  CumulativeSum2D J(grid, 'J');
  CumulativeSum2D O(grid, 'O');
  CumulativeSum2D I(grid, 'I');

  for(int i=0; i<k; ++i) {
    int x1,y1,x2,y2; cin >> y1 >> x1 >> y2 >> x2;
    --x1, --y1, --x2, --y2;
    cout << J.query(y1,x1,y2,x2) << " ";
    cout << O.query(y1,x1,y2,x2) << " ";
    cout << I.query(y1,x1,y2,x2) << endl;
  }
#endif
}
