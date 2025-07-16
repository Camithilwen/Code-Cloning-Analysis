#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int A, B, M; cin >> A >> B >> M;
  vector<int> a(A);
  vector<int> b(B);
  int minA = 100001;
  int minB = 100001;
  
  rep(i,A){
    cin >> a[i];
    minA = min(minA,a[i]);
  }
  rep(i,B){
    cin >> b[i];
    minB = min(minB,b[i]);
  }
  
  int ans = minA + minB;
  rep(i,M){
    int x,y,c; cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans, a[x] + b[y] - c);
  }
  cout << ans << endl;



  return 0;
}

