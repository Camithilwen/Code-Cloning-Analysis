#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<int> scinence = {a,b,c,d};
  vector<int> sorcial = {e,f};
  sort(scinence.begin(), scinence.end());
  int ans = 0;
  for(int i = 3; i > 0;--i) ans += scinence.at(i);
  ans += max(e,f);
  cout << ans << endl;
}
