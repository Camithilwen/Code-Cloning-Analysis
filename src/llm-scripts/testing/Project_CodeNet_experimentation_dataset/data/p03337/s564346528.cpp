#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

void solve(ll A, ll B) { cout << max({A + B, A - B, A * B}) << endl; }

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}
