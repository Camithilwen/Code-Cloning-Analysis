#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main(){
  int n,h,w; cin >> n >> h >> w;
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(h+i-1 >= n) break;
      if(w+j-1 >= n) break;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
