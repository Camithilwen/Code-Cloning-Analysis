#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b;
  cin >> a >> b;
  int count = 0;
  for (int i = a; i < b+1; i++) {
    int ii = i;
    vector<int> vec(5);
    rep(j, 5) {
      vec.at(j) = (ii % 10);
      ii /= 10;
    }
    if (vec.at(0) == vec.at(4)) {
      if (vec.at(1) == vec.at(3)) {
        count++;
      }
    }
  }
  cout << count << endl;
}
      
