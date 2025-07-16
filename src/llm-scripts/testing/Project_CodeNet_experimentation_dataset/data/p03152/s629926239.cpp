#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,M;
  cin >> N >> M;
  int A[N],B[M];
  int Acnt[1100000];
  int Bcnt[1100000];
  ll a = 0;
  ll b = 0;
  ll ans = 1;
  for (int i = 0; i < 1100000; i++) {
    Acnt[i] = 0; Bcnt[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    Acnt[A[i]]++;
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    Bcnt[B[i]]++;
  }
  for (int i = N*M; i >= 1; i--) {
    int s = Acnt[i] + Bcnt[i];
    if (s > 2) {
      ans = 0;
    } else if (s == 2) {
      ans *= 1;
      a++; b++;
    } else if (s == 1) {
      if (Acnt[i] == 1) {
        ans *= b;
        a++;
      } else {
        ans *= a;
        b++;
      }
    } else {
      ll c = a*b;
      c -= ((N*M) - i);
      ans *= c;
    }
    ans %= Mod;
  }
  if (a == N && b == M) {
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}