#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll a, b, k;
  cin >> a >> b >> k;
  ll count = 0;
  while(count<k){
    if(a%2==1){
      a--;
    }
    b += a / 2;
    a /= 2;
    count++;
    if(count==k){
      break;
    }
    if(b%2==1){
      b--;
    }
    a += b / 2;
    b /= 2;
    count++;
  }
  cout << a << " " << b << endl;
}