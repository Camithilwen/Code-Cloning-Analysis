#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

signed main(){
  int n;
  string s;
  cin >> n >> s;

  vi a(2*n);
  rep(i, 0, 2*n){
    a[i] = ((s[i] == 'B') + (i%2 == 0)) % 2;
  }

  int ans = 1, cnt = 0;
  rep(i, 0, 2*n){
    if(a[i]){
      (ans *= cnt) %= mod;
      cnt--;
    }else{
      cnt++;
    }
  }

  if(cnt) ans = 0;

  rep(i, 1, n+1) (ans *= i) %= mod;

  cout << ans << endl;
  
//  rep(i, 0, 2*n) cout << a[i] << " ";
//  cout << endl;

  return 0;
}
