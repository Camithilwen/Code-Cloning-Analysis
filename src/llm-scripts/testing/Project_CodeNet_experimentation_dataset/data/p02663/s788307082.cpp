#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll h,m;
  cin >> h >> m;
  ll s=h*60+m;
  cin >> h >> m;
  ll g=h*60+m;
  ll k;
  cin >> k;
  cout << g-s-k << endl;
}