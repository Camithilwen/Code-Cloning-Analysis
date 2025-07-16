// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int G[500][500];
int ACC[501][501];

int main() {
  int n, m, q; in(n),in(m),in(q);
  loop(i,0,m) {
    int l, r; in(l),in(r);
    l--;r--;
    G[l][r]++;
  }
  
  loop(y,0,n) {
    loop(x,0,n) {
      ACC[y+1][x+1] = ACC[y+1][x] + ACC[y][x+1] - ACC[y][x] + G[y][x];
    }
  }
  
  // loop(y,0,n+1) {
  //   loop(x,0,n+1) {
  //     print(ACC[y][x], " ");
  //   }
  //   print("");
  // }
  
  loop(i,0,q) {
    int l,r; in(l),in(r);
    int cnt = ACC[r][r];
    cnt += ACC[l-1][l-1];
    cnt -= ACC[l-1][r];
    cnt -= ACC[r][l-1];
    // print(ACC[r][r]);
    // print(ACC[l-1][l-1]);
    // print(ACC[l-1][r]);
    // print(ACC[r][l-1]);
    print(cnt);
  }
  return 0;
}
