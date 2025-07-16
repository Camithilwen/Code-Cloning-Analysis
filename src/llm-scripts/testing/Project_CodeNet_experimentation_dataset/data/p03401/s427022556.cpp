/*
 * atcoder/abc092_2nd/c.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

int N;
vector<int> J;
ll acc[100100] = {0};
void solve() {
  cin >> N;
  J.push_back(0);
  int j;
  loop(n,0,N) {
    cin >> j;
    J.push_back(j);
  }
  J.push_back(0);
  N+=2;
  loop(n,1,N) {
    acc[n] = acc[n-1] + abs(J[n]-J[n-1]);
  }
  //     n
  // 0 3 5 -1 0
  loop(n,1,N-1) {
    cout << acc[n-1] + abs(J[n-1]-J[n+1]) + (acc[N-1]-acc[n+1]) << endl;
  }
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
