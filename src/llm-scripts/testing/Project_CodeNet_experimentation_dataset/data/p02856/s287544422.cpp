#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int m;
  cin >> m;
  ll now = 0;
  ll nine_count = 0;
  ll d = 0;
  rep(i,m){
    ll a,b;
    cin >> a >> b;
    d += b;
    nine_count += (a * b)/9;
    now += (a * b) % 9;
  }
  nine_count += now/9;
  
  if(now%9 == 0) cout << nine_count + d - 2 << endl;
  else cout << nine_count + d - 1 << endl;  

  return 0;
}

