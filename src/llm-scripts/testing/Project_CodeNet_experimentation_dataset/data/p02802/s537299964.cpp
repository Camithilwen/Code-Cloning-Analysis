// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n, m; in(n),in(m);
  vector<bool> ac(n+1, false);
  vector<int> wa(n+1, 0);
  int p; string s;
  loop(i,0,m) {
    in(p),in(s);
    if (ac[p]) continue;
    if (s == "WA") wa[p]++;
    else ac[p] = true;
  }
  loop(p,1,n+1) if (!ac[p]) wa[p] = 0;
  
  int ans1 = 0;
  for (auto&&b: ac) ans1+=b;
  int ans2 = 0;
  for (auto&&w: wa) ans2+=w;
  print(ans1, " ");
  print(ans2);
  return 0;
}
