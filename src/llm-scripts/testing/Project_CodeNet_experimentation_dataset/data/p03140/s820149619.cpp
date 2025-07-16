#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int N; cin >> N;
  string A, B, C; cin >> A >> B >> C;

  int cnt = 0;
  REP(i, N) {
    if(A[i] == B[i] && B[i] == C[i]) {
      
    }
    else if(A[i] == B[i]) {
      cnt++;
    }
    else if(A[i] == C[i]) {
      cnt++;
    }
    else if(C[i] == B[i]) {
      cnt++;
    } else {
      cnt = cnt + 2;
    }
  }

  cout << cnt << endl;
}