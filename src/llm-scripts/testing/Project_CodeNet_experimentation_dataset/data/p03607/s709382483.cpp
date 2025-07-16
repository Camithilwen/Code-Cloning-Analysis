#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int n;
  cin >> n;
  map<int, bool> mp;
  REP(i,n){
    int a;
    cin >> a;
    if(mp[a]) mp[a] = false;
    else mp[a] = true;
    }

  int cnt = 0;
  for(auto x: mp){
    if(x.second) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
