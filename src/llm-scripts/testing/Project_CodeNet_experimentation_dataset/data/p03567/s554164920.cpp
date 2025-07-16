#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
//const int MOD = 1000000007;
const ll MOD=998244353;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main(){
  string s;
  cin>>s;
  int n=s.size();
  rep(i,n-1){
    string t=s.substr(i,2);
    if(t=="AC"){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
