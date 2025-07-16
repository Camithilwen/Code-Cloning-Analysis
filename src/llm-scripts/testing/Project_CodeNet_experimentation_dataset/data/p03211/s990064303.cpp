#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string S;
  cin >> S;

  int len = S.size();

  int ans = 1000;
  for (int i = 0; i < len - 2; i++){
    int x = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + (S[i + 2] - '0');
    ans = min(abs(x - 753), ans);
  }
  cout << ans << endl;
}
