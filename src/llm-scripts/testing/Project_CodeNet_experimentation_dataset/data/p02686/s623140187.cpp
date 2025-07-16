#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int N = (int) 1e6 + 7;
int n, sumtop;

struct T {
  int top;
  int mn;
};

bool cmp1(T a, T b) {
  return a.mn > b.mn;
}

bool cmp2(T a, T b) {
  return min(a.mn, a.top + b.mn) > min(b.mn, b.top + a.mn);
 ///return a.top - a.mn > b.top - b.mn;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<T> a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int top = 0, mn = 0;
    for (auto &ch : s) {
      if (ch == '(') {
        top++;
      } else {
        top--;
      }
      mn = min(mn, top);
    }
    if (top >= 0) {
      a.push_back({top, mn});
    } else {
      b.push_back({top, mn});
    }
    sumtop += top;
  }
  if (sumtop != 0) {
    cout << "No\n";
    return 0;
  }
  sort(a.begin(), a.end(), cmp1);
  sort(b.begin(), b.end(), cmp2);
  int cur = 0;
  for (auto &it : a) {
    if (cur + it.mn < 0) {
      cout << "No\n";
      return 0;
    }
    cur += it.top;
  }
  for (auto &it : b) {
    if (cur + it.mn < 0) {
      cout << "No\n";
      return 0;
    }
    cur += it.top;
  }
  cout << "Yes\n";
  return 0;
}
