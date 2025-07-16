#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }




int minimam(int a,int b,int c, int d);

int main() {
  int a,b,c,d; cin >> a >> b >> c >> d;
  int num;
  num = minimam(a,b,c,d);
  cout << num << endl;
  return 0;
}
int minimam(int a,int b,int c, int d) {
  return min(a,b)+min(c,d);
}