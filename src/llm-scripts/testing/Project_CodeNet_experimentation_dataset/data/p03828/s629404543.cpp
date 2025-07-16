#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <math.h>
#define MOD 1000000007

using namespace std;

ifstream fin("../data.txt");

int x;

unordered_map<int, long long> factorization(int x) {
  unordered_map<int, long long> factors;
  while(x % 2 == 0) {
    factors[2]++;
    x /= 2;
  }

  for (int i = 3; i <= sqrt(x); i++) {
    while(x % i == 0) {
      factors[i]++;
      x /= i;
    }
  }

  if (x != 1) factors[x]++;
  // for (auto aux : factors) {
  //   cout << "(" <<  aux.first << ", " << aux.second << ") ";
  // }
  // cout << "\n";
  return factors;
}

int main() {

  cin >> x;
  unordered_map<int, long long> factors;
  for (int n = 2; n <= x; n++) {
    unordered_map<int, long long> currFactors = factorization(n);
    for (auto aux : currFactors) {
      factors[aux.first] += aux.second;
    }
  }

  long long ans = 1;
  for (auto aux : factors) {
    ans *= (aux.second + 1LL);
    ans %= MOD;
  }


  cout << ans;

  return 0;
}
