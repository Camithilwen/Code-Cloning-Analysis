#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
#include <algorithm>
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
//#define cocount cout << count << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define Cinint(n) int n;\
cin >> n;
#define Cinvecint(a, n) vector<int> a(n);\
for (int i = 0; i < (int)(n); i++) {\
  int num;\
  cin >> num;\
  a.at(i) = num;\
}
#define Cinstring(s) string s;\
cin >>s;

  

int main() {
  Cinint(n);
  Cinstring(s);
  int64_t count = 0;
  int64_t Rcount = 0;
  int64_t Gcount = 0;
  int64_t Bcount = 0;
  rep(i, n) {
    if (s.at(i) == 'R') {
      Rcount++;
    }
    else if (s.at(i) == 'G') {
      Gcount++;
    }
    else {
      Bcount++;
    }
  }
  count = Rcount*Gcount*Bcount;
  rep(i, n-2) {
    for (int j = i+1; j < n-1; j++) {
      int sa = j-i;
      int k = j+sa;
      if (k <= n-1) {
        if (s.at(i) == 'R') {
          if (s.at(j) == 'G') {
            if (s.at(k) == 'B') {
              count--;
            }
          }
          else if (s.at(j) == 'B') {
            if (s.at(k) == 'G') {
              count--;
            }
          }
        }
        else if (s.at(i) == 'G') {
          if (s.at(j) == 'B') {
            if (s.at(k) == 'R') {
              count--;
            }
          }
          else if (s.at(j) == 'R') {
            if (s.at(k) == 'B') {
              count--;
            }
          }
        }
        else {
          if (s.at(j) == 'R') {
            if (s.at(k) == 'G') {
              count--;
            }
          }
          else if (s.at(j) == 'G') {
            if (s.at(k) == 'R') {
              count--;
            }
          }
        }
      }
    }
  }
  cout << count << endl;
}
