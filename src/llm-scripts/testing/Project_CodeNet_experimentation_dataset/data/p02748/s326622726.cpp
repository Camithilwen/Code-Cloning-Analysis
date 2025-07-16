#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A,B,M,p{100000},q{100000},mi{200000},x,y,c;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  for (auto &e: a) {
    cin >> e;
    if(e<p) p = e;
  }
  for (auto &e: b) {
    cin >> e;
    if(e<q) q = e;
  }
  mi = p+q;
  while(cin >> x >> y >> c) {
    mi = min(mi,a[x-1]+b[y-1]-c);
  }
  cout << mi << endl;
  return 0;
}
