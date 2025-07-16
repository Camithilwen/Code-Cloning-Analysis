#include "bits/stdc++.h"

using ll = long long;
using namespace std;

void go(int x) {
   cout << x << endl;
   exit(0);
}

void solve() {
   int x, y;
   cin >> x >> y;
   if(x == 0 || y == 0) {
      if(x == 0) {
         if(y >= 0) go(y - x);
         else go(abs(y) + 1);
      } else if(y == 0) {
         if(x < 0) go(abs(x));
         else go(abs(x) + 1);
      }
   }
   if(x < y) {
      if(x * 1LL * y >= 0) {
         go(y - x);
      } else {
         go(1 + abs(abs(y) - abs(x)));
      }
   } else if(x == y) {
      go(0);
   } else {
      //x > y;
      if(x * 1LL * y >= 0) {
         go(2 + abs(abs(x) - abs(y)));
      } else {
         go(1 + abs(abs(x) - abs(y)));
      }

   }
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