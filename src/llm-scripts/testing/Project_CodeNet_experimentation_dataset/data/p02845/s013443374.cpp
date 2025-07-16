#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll mod = 1000000007;
int main(){
  int n; cin >> n;
  vector <ll> a(n);
  rep(i, n){
    cin >> a[i];
    a[i]++;
  }
  vector <ll> num(n+1);
  num[0] = 3;
  ll ans = 1;
  rep(i, n){
    if (num[a[i]-1] < 0){
      cout << 0 << endl;
      return 0;
    }
    ans *= num[a[i]-1];
    ans %= mod;
    num[a[i]-1]--;
    num[a[i]]++;
  }
  cout << ans <<endl;
}