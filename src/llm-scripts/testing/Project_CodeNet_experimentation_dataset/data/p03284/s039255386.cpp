#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N, K; cin >> N >> K;
  if (N % K == 0) cout << 0 << endl;
  else            cout << 1 << endl;
}
