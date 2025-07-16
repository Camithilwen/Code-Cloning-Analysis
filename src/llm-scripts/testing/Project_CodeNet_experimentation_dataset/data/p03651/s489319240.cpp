#include <iostream>
#include <numeric>

using namespace std;

const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

int main() {
  int N, K, M{}, D{}, A;
  cin >> N >> K;
  while (cin >> A) {
    M = max(M, A);
    if (D) D = gcd(D, A);
    else D = A;
  }
  cout << (K <= M && (M - K) % D == 0 ? YES : NO) << endl;
}
