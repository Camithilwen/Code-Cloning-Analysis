// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  vector<int> A(3); loop(i,0,3) cin >> A[i];
  int k; cin >> k;
  while (k--) {
    sort(A.rbegin(), A.rend());
    A[0] *= 2;
  }
  cout << A[0]+A[1]+A[2] << endl;
  return 0;
}
