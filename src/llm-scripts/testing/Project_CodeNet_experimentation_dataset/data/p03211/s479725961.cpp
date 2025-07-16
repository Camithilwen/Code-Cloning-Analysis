#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  string S; cin >>S;
  ll ans = INF;
  rep(i,S.size()-2){
    ll ints = stoi(S.substr(i,3)); 
    ans = min(ans,abs(753 - ints));
  }

  cout << ans << endl;
	return 0;
}

