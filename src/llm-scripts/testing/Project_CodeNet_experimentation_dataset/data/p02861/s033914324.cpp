#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int main() {
  int N;
  int A[8], B[8];
  int NUM[8];
  double sum = 0;
  cin >> N;
  rep(i, N) {
    cin >> A[i] >> B[i];
  }
  rep(i, N) NUM[i] = i;
  do {
    rep(i, N-1) {
      sum += sqrt(pow(A[NUM[i+1]]-A[NUM[i]], 2)
                + pow(B[NUM[i+1]]-B[NUM[i]], 2));
    }
  } while(next_permutation(NUM, NUM+N));
  rep(i, N) sum /= (i+1);
  cout << fixed << setprecision(10) << sum << endl;
  return 0;
}
