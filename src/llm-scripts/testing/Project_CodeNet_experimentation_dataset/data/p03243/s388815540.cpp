#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  int ans;
  for(int i = n; i <= 999; i++){
    if(i/100 == (i/10)%10 && i/100 == i %10){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}

