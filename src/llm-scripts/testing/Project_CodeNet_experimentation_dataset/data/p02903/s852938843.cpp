#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  int a, b;
  cin >> a >> b;
  int one = 1;
  int zero = 0;
  bool yes = true;
  rep(i, h) {
    if (i >= b && yes) {
      swap(zero, one);
      yes = false;
    }
    rep(j, w) {
      if(j < a) cout << one;
      else cout << zero;
    }
    cout << endl;
  }
}