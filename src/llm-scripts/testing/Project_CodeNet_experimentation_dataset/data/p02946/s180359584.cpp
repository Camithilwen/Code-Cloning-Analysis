#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int K, X; cin >> K >> X;
  for (int i = X - K + 1; i < X + K; ++i) {
    cout << i << " ";
  }
  cout << endl;
}
