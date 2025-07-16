#include "bits/stdc++.h"
using ll = long long;
using namespace std;

const double pi = acos(-1);

pair <double, double> rotate(int x, int y, int degree, double d) {
   double theta = (2 * pi / 360) * degree;
   double x_ = x * cos (theta) - y * sin(theta);
   double y_ = x * sin (theta) + y * cos(theta);
   x_ *= d;
   y_ *= d;
   return {x_, y_};
}

const double eps = 1e-3;

int near(double x) {
   for(int i = (int)(x - 2); i < (int)(x + 2); i++) {
      if(abs(i - x) < eps) {
         return i;
      }
   }
   return 0;
}
void solve() {
   string s;
   int a, b;
   cin >> a >> b >> s;

   bool ok = true;
   ok &= s[a] == '-';
   for(int i = 0; i < s.length(); i++) {
      if(i == a)
         continue;
      else ok &= s[i] >= '0' && s[i] <= '9';
   } 
   cout << (ok?"Yes":"No") << endl;
}

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
