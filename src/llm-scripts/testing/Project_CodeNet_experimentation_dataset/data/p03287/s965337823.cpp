// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n; ll m; in(n),in(m);
  vector<ll> A(n);
  loop(i,0,n) in(A[i]);
  loop(i,0,n) A[i]%=m;
  ll rem = 0;
  map<ll, ll> C;
  C[rem]++;
  loop(i,0,n) {
    rem = (rem + A[i]) % m;
    C[rem]++;
  }
  ll ans = 0;
  for (auto &&c: C) {
    ans += (c.second * (c.second - 1)) / 2;
  }
  print(ans);
  return 0;
}
