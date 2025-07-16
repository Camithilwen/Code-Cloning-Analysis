#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
 
#define mod 1000000007
#define inf 1000000000
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define popcount(x) __builtin_popcountll(x)
 
const long double PI = acos(-1);
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
 
int main(){
  ll x, y;
  cin >> x >> y;
  ll ans = 0;
  if(x == 1) ans += 300000;
  if(x == 2) ans += 200000;
  if(x == 3) ans += 100000;
  if(y == 1) ans += 300000;
  if(y == 2) ans += 200000;
  if(y == 3) ans += 100000;

  if(x == 1 && y == 1) ans += 400000;

  cout << ans << endl;
  return 0;
}