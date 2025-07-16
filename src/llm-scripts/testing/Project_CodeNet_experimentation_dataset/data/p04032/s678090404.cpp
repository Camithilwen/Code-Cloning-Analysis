// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  string s; in(s);
  int n = s.size();
  loop(len,2,4) {
    if (len > n) break;
    loop(l,0,n-len+1) {
      map<char, int> M;
      int max_ = 0;
      loop(i,l,l+len) {
        M[s[i]]++;
        max_ = max(max_, M[s[i]]);
      }
      if (max_ > len/2) {
        cout << l+1 << " " << l+len << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}
