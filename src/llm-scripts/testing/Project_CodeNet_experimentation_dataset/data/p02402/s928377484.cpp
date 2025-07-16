#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
  vector<int> result;
  string n;
  string input;

  getline(cin, n);
  getline(cin, input);
  istringstream iss(input);
  string num;

  while (getline(iss, num, ' ')) {
    result.push_back(stoi(num));
  }

  long long min = *min_element(result.begin(), result.end());
  long long max = *max_element(result.begin(), result.end());
  long long sum = accumulate(result.begin(), result.end(), 0LL);

  cout << min << " " << max << " " << sum << endl;
}
