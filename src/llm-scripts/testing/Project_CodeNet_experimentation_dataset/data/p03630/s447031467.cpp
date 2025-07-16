#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int SolveMaxRectangle(const vector<int>& input_xs, int w) {
  vector<int> xs(input_xs.begin(), input_xs.end());
  xs.push_back(0);

  int max = w;
  stack<pair<int, int>> stack;
  for (int i = 0; i < xs.size(); i++) {
    if (stack.empty()) {
      stack.push(make_pair(xs[i], i));
    } else {
      if (xs[i] >= stack.top().first) {
        stack.push(make_pair(xs[i], i));
      } else {
        int push_index = i;
        while (!stack.empty() && xs[i] < stack.top().first) {
          int r_width = i - stack.top().second + 1;
          int r_area = r_width * stack.top().first;
          UpdateMax(max, r_area);
          push_index = stack.top().second;
          // if (DEBUG) {
          //   cout << "i: " << i << endl;
          //   cout << "stack.top().second: " << stack.top().second << endl;
          //   cout << "v: " << stack.top().first << endl;
          //   cout << "r_area: " << r_area << endl;
          // }
          stack.pop();
        }

        stack.push(make_pair(xs[i], push_index));
      }
    }
  }
  return max;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> board(h);
  for (int r = 0; r < h; r++) {
    cin >> board[r];
  }

  vector<vector<int>> dp1 = Make2DVector(h - 1, w, -1);
  for (int r = 0; r < h - 1; r++) {
    int current = -1;
    for (int c = w - 1; c >= 0; c--) {
      if (c == w - 1) {
        current = board[r][c] == board[r + 1][c];
        dp1[r][c] = 1;
      } else {
        if ((board[r][c] == board[r + 1][c]) == current) {
          dp1[r][c] = dp1[r][c + 1] + 1;
        } else {
          current = board[r][c] == board[r + 1][c];
          dp1[r][c] = 1;
        }
      }
    }
  }

  if (DEBUG) {
    for (int r = 0; r < h - 1; r++) {
      cout << "dp1[" << r << "]: " << dp1[r] << endl;
    }
  }

  int ans = 0;
  for (int c = 0; c < w; c++) {
    vector<int> xs(h - 1);
    for (int r = 0; r < h - 1; r++) {
      xs[r] = dp1[r][c];
    }
    if (DEBUG) {
      cout << "SolveMaxRectangle(" << c << ")" << endl;
      cout << "xs: " << xs << endl;
    }
    int max_rectanle = SolveMaxRectangle(xs, w - c);
    if (DEBUG) cout << "c: " << c << " max_rectangle: " << max_rectanle << endl;
    UpdateMax(ans, max_rectanle);
  }
  cout << ans << endl;
}