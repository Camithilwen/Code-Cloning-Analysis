#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using int64 = long long;
using TP = tuple<int64,int,int>;
int main() {
  int n;
  cin >> n;
  vector<TP> ab;
  for (int i=0; i<n; i++) {
    int a, b;
    cin >> a >> b;
    ab.emplace_back(a+b, a, b);
  }
  sort(ab.rbegin(), ab.rend());
  
  int64 a = 0;
  int64 b = 0;
  for (int i=0; i<n; i++) {
    if (i%2) b += get<2>(ab[i]);
    else a += get<1>(ab[i]);
  }
  
  cout << (a-b) << endl;
}