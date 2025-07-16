#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  long long x;
  cin >> x;

  long long count = (x / (5 + 6)) * 2;
  if (x % (5 + 6) == 0) {}
  else if (x % (5 + 6) <= 6) count++;
  else count += 2;

  cout << count << endl;

  return 0;
}