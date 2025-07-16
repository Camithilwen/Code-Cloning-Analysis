#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);
// int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
// int a[12][12];

void solve() {
  string s; cin >> s;
  string hitachi = "";
  for (int i= 1; i <=5; i++) {
    hitachi += "hi";
    if (hitachi == s) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;

}


int main() {
  solve();
  return 0;
}
