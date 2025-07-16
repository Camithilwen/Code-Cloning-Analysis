#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  string s;
  int w;
  cin >> s >> w;
  string ans = "";
  for(int i = 0; ; ++i) {
    if(i * w >= s.length()) break;
    ans += s.substr(i * w, 1);
  }
  cout << ans << endl;
}