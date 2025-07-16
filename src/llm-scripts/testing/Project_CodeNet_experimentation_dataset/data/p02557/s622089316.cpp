#include <iostream>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> A(N);
  unordered_map<int, int> Acnt;
  rep(i, N) {
    cin >> A[i];
    Acnt[A[i]]++;
  }
  vector<int> B(N);
  unordered_map<int, int> Bcnt;
  rep(i, N) {
    cin >> B[i];
    Bcnt[B[i]]++;
  }

  for (auto& a : Acnt) {
    if (Bcnt.count(a.first) && (N < a.second + Bcnt[a.first])) {
      cout << "No" << endl;
      return 0;
    }
  }

  int j = 0;
  int prev = -1;
  rep(i, N) {
    if (prev != A[i]) j = 0;
    if (A[i] == B[i]) {
      for (; j < N; ++j) {
        if (A[i] != A[j] && A[i] != B[j]) {
          swap(B[i], B[j]);
          break;
        }
      }
    }
    prev = A[i];
  }

  cout << "Yes" << endl;
  rep(i, N) {
    if (i != 0) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}
