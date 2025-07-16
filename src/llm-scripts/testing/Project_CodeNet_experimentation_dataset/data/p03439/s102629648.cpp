#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
#define ve vector
#define pint pair<int,int>
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
// *max_element(all(d))
int solve(){
  int n;
  cin >> n;
  cout << 0 << endl;
  string f;
  cin >> f;
  int l = 0,r = n;
  if(f!="Vacant")while(1){
    int m = (l + r) / 2;
    cout << m << endl;
    string s;
    cin >> s;
    if(s == "Vacant")break;
    if(m % 2 && s != f || m % 2 == 0 && s == f)l = m + 1;
    else r = m;
  }
  return 0; 
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}