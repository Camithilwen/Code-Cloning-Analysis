#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<int> L(Q);
  vector<int> R(Q);
  vector<int> A(N);
  
  for (int i=0; i<Q; i++) {
    cin >> L[i] >> R[i];
  }
  
  int cnt = 0;
  A[0] = 0;
  for (int i=1; i<N; i++) {
    if (S[i] == 'C' && S[i-1] == 'A') cnt++;
    A[i] = cnt;
  }
  
  for (int i=0; i<Q; i++) {
    cout << A[R[i]-1] - A[L[i]-1] << endl;
  }
  
  return 0;
}
