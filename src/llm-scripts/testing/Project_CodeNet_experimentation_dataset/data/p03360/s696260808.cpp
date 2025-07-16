#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> abc(3);
  int k;
  cin >> abc[0] >> abc[1] >> abc[2];
  cin >> k;

  vector<int>::iterator iter = max_element(abc.begin(), abc.end());
  size_t index = distance(abc.begin(), iter);

  abc[index] *= (int)pow(2.0, (double)k);
  cout << accumulate(abc.begin(), abc.end(), 0) << endl;

  return 0;
}
