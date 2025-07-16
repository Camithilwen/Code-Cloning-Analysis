#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  int cnt_w = 0, cnt_e = 0;
  int ans = pow(10, 6);
  vector<char> A(N);
  vector<int> S_W(N, 0);
  vector<int> S_E(N, 0);
  rep(i, N){
    cin >> A[i];
  }
  rep(i, N){
    if (A[i]=='W'){
      cnt_w++;
      S_W[i] = cnt_w;
      S_E[i] = cnt_e;
    }
    if (A[i]=='E'){
      cnt_e++;
      S_W[i] = cnt_w;
      S_E[i] = cnt_e;
    }
  }
  rep(i, N){
    if (i==0) ans = min(ans, S_E[N-1] - S_E[i]);
    if (i==N-1) ans = min(ans, S_W[N-1]);
    else ans = min(ans, (S_W[i] + (S_E[N-1] - S_E[i])));
  }
  cout << ans << endl;
}