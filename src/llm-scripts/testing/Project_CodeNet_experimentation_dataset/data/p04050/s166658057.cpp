#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int cnt = 0, s1 = -1, s2 = -1;
  vector<int> a(m);
  for ( int i = 0; i < m; ++ i) {
    cin >> a[i]; 
    if( a[i] & 1) {
      ++ cnt;
      if( cnt == 1) {
        s1 = i;
      } else {
        s2 = i;
      }
    }
  }
  if( cnt >= 3) {
    cout << "Impossible\n";
  } else {
    if( m == 1) {
      cout << a[0] << "\n";
      cout << 1 + (n != 1) << "\n" << 1;
      if( n != 1) {
        cout << " " << n-1 << "\n";
      }
    } else {
      if( ~ s1) {
        swap(a[s1], a[0]);
      } 
      if( ~ s2) {
        swap(a[s2], a[m-1]);
      }
      for ( auto v : a) {
        cout << v << " ";
      } 
      a[0] ++; a[m-1] --;
      if( !a[m-1]) {
        a.pop_back();
      }
      cout << "\n" << a.size() << "\n";
      for ( auto v : a) {
        cout << v << " ";
      }
    }
  }
  return 0;
}