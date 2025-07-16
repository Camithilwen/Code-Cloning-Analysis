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
  int A, B;
  cin >> A >> B;
  int mx;
  mx = std::max(A+B, std::max(A-B, A*B));

  cout << mx << endl;

  return 0;
}
