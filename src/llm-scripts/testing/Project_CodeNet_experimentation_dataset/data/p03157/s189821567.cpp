#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int h, w;
  cin >> h >> w;
  vector<string> m(h);
  for (int i = 0; i < h; ++i) {
    cin >> m[i];
  }

  vector<vector<bool>> seen(h, vector<bool>(w, false));

  long long ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; j++) {
      long long b_cnt, w_cnt;
      b_cnt = w_cnt = 0;
      stack<array<int, 3>> st;
      st.push({i, j, m[i][j] != '#'});
      while (!st.empty()) {
        auto t = st.top();
        int y = t[0], x = t[1], p = t[2];
        st.pop();

        if (y < 0 || y >= h || x < 0 || x >= w) {
          continue;
        }

        if (seen[y][x] || p == m[y][x]) {
          continue;
        }

        seen[y][x] = true;

        if (m[y][x] == '.') {
          w_cnt++;
        } else {
          b_cnt++;
        }

        st.push({y - 1, x, m[y][x]});
        st.push({y + 1, x, m[y][x]});
        st.push({y, x + 1, m[y][x]});
        st.push({y, x - 1, m[y][x]});
      }

      ans += b_cnt * w_cnt;
    }
  }

  cout << ans << '\n';
}
