#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
typedef long long ll;
const int inf = 100100100;



//conbinatin (2002,2) = 

int main(){
  ll n,y;
  cin >> n >> y;

  rep(i,n+1){
    rep(j,n+1-i){
      int k = n-i-j;
        if(10000*i+5000*j+1000*k == y) {
          cout << i << " " << j << " " << k  << endl;
          return 0;
        }
      }
    }
  cout << "-1 -1 -1" << endl;
}
