#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
   cin.tie(0);
   ios::sync_with_stdio(false);
   ll k, t;
   cin >> k >> t;
   vector<ll> a(t);
   for(ll i = 0;i < t;i++) {
      cin >> a[i];
   }
   ll cnt = 0;
   ll before_idx = -1;
   for(ll i = 0;i < k;i++) {
      ll m = 0;
      ll idx = -1;
      for(ll j = 0;j < t;j++) {
         if (before_idx != j) {
            if (m < a[j]) {
               m = a[j];
               idx = j;
            }
         }
      }
      if (m==0) {
         a[before_idx]--;
         cnt++;
      } else {
         a[idx]--;
         before_idx = idx;
      }
   }
   cout << cnt << endl;
}