#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n%k==0) {
    printf("0\n");
  } else {
    printf("1\n");
  }
  return 0;
}