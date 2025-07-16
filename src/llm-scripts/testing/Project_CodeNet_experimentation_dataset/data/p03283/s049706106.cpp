#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

struct CumulativeSum2D {
  vector<vector<long long>> csum;
  template<typename T>
  CumulativeSum2D(vector<vector<T>> input) : csum(input.size() + 1, vector<long long>(input[0].size() + 1, 0)) {
    for(int i = 0; i < input.size(); i++) for(int j = 0; j < input[i].size(); j++)
      csum[i+1][j+1] += csum[i+1][j] + csum[i][j+1] - csum[i][j] + input[i][j];
  }
  CumulativeSum2D(vector<string> input, char target) : csum(input.size() + 1, vector<long long>(input[0].size() + 1, 0)) {
    for(int i = 0; i < input.size(); i++) for(int j = 0; j < input[i].size(); j++)
      csum[i+1][j+1] += csum[i+1][j] + csum[i][j+1] - csum[i][j] + (input[i][j]==target);
  }
  long long query(int x_left, int y_top, int x_right, int y_bottom) { /* 0-indexed, inclusive */
    return csum[x_right+1][y_bottom+1] - csum[x_right+1][y_top] - csum[x_left][y_bottom+1] + csum[x_left][y_top];
  }
};

signed main() {
  int n,m,Q; cin >> n >> m >> Q;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  rep(i,m) {
    int l,r; cin >> l >> r;
    grid[l-1][r-1]++;
  }
  CumulativeSum2D cs(grid);
  rep(i,Q) {
    int p,q; cin >> p >> q; --p,--q;
    cout << cs.query(p,p, q,q) << endl;
  }
}
