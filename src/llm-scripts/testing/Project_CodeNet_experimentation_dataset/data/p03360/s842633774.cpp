#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  vector<int> A(3); cin >> A[0] >> A[1] >> A[2];
  int K; cin >> K;
  sort(A.begin(),A.end());
  for (int i = 0; i < K; ++i) A[2] *= 2;
  int sum = A[0] + A[1] + A[2];
  cout << sum << endl;
}
