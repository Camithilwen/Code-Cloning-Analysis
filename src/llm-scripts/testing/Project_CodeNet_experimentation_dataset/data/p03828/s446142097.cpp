#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
#define MOD 1000000007;

void solve(){
  int n; cin >> n;
  long long ans = 1;
  vector<int> pn;
  map<int, int> mp;
  for(int i = 2; i <= n; ++i){
    int cnt = 0;
    for(int j = 1; j <= i; ++j){
      if(i % j == 0)cnt++;
    }
    if(cnt == 2) pn.push_back(i);
  }
  for(int i = 2; i <= n; ++i){
    int tmp = i;
    while(tmp !=1){
      for(auto p : pn){
        if(tmp%p == 0) {
          mp[p]++;
          tmp/=p;
          if(tmp == 1)break;
        }
      }
    }
  }
  for(auto m: mp){
    ans *= (m.second+1);
    ans %= MOD;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0; 
}