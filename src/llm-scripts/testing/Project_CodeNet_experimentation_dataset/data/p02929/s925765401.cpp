#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  string T;
  char c = 'W';
  for (int i = 0; i < N * 2; i++){
    if (S[i] != c){
      T += 'L';
      c = 'B' + 'W' - c;
    } else {
      T += 'R';
      c = 'B' + 'W' - c;
    }
  }
  int cnt = 0;
  for (int i = 0; i < N * 2; i++){
    if (T[i] == 'L'){
      cnt++;
    }
  }
  if (cnt != N){
    cout << 0 << endl;
  } else {
    int L = 0;
    long long ans = 1;
    for (int i = 0; i < N * 2; i++){
      if (T[i] == 'L'){
        L++;
      } else {
        ans *= L;
        ans %= MOD;
        L--;
      }
    }
    for (int i = 1; i <= N; i++){
      ans *= i;
      ans %= MOD;;
    }
    cout << ans << endl;
  }
}