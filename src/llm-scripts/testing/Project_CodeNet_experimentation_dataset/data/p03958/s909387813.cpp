#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int K, T;
  cin >> K >> T;

  vector<int> a(T);
  int maximum = 0;
  for (int i = 0; i < T; ++i) {
    cin >> a[i];
    maximum = max(maximum, a[i]);
  }

  cout << max(maximum - (K - maximum) - 1, 0) << endl;

  return 0;
}