#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  long N;
  vector<long> t;

  cin >> N;
  for (int i = 0; i < 5; ++i) {
    long k;
    cin >> k;
    t.push_back(k);
  }
  long min = *min_element(begin(t), end(t));
  cout << ((N - 1) / min) + 5 << endl;
  return 0;
}
