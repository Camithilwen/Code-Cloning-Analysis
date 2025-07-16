#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   map<int, int> mp;
   for(int i = 0; i < n; i++) {
       int foo;
       cin >> foo;
       mp[foo]++;
   }
   int ans = 0;
   for(auto p : mp) {
       if(p.second & 1) ans++;
   }
   cout << ans << endl;
}