#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
 
const double PI = 3.14159265358979323846;
/*Graph t;
void dfs(int v, int pv=-1){
    for(int vn: t[v]){
        if (vn == pv) continue;
        dfs(vn, v);
    }
}*/
int main() {
  ll n,k;
  cin >> n >> k;
  ll ma;
  cin >> ma;
  ll g=ma;
  rep(i,n-1){
    ll o;
    cin >> o;
    ma=max(o,ma);
    g=gcd(g,o);
  }
  if(n==1){
    if(ma==k)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  else if(k%g==0&&ma>=k) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
