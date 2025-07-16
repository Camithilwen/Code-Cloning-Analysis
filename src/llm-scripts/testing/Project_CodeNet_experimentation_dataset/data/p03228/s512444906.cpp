#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  int a, b, k;
  cin >> a >> b >> k;

  rep(i, k) {
    if(i % 2 == 0) {
      a /= 2;
      b += a;
    } else {
      b /= 2;
      a += b;
    }
  }
  cout << a << " " << b << endl;
}