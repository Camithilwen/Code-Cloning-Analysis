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
    int x, y, z;
    cin >> x >> y >> z;
    int ansx, ansy, ansz;
    ansx = y;
    ansy = x;
    x = y;
    y = ansy;
    ansx = z;
    ansz = x;
    cout << ansx << " " << ansy << " " << ansz << endl;
}