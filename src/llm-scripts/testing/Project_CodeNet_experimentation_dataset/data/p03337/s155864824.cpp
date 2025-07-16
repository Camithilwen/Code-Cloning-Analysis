#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int a,b;
  cin >> a >> b;
  int ans = a+b;
  ans = max(ans,a-b);
  ans = max(ans,a*b);
  cout << ans << endl;
}