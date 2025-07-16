#include <cmath>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>
 
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
  os << "[";
  for(int i = 0; i < int(v.size()); i++) {
    os << v[i] << (i == int(v.size()) - 1 ? "" : ", ");
  }
  os << "]";
  return os;
}
 
// n 以下の素数のリストを返す O(nlog(log(n)))
std::vector<int> eratosthenes(int n) {
  std::vector<int> is_prime(n + 1, 1);
  std::vector<int> primes;

  is_prime[0] = is_prime[1] = 0;
  primes.push_back(2);
  for(int i = 3; i <= n; i += 2) {
    if(is_prime[i]) {
      primes.push_back(i);
      for(int j = 3; i * j <= n; j += 2) {
        is_prime[i * j] = 0;
      }
    }
  }

  return primes;
}
 
int main() {
  int n;
  std::vector<int> primes = eratosthenes(10000);
 
  while(cin >> n, n) {
    int a = 2, b = 3;
    for(int i = 1; i < primes.size(); i++) {
      if (primes[i] > n) break;

      if(primes[i] - primes[i - 1] == 2) {
        a = primes[i - 1];
        b = primes[i];
      }
    }
    cout << a << " " << b << endl;
  }
 
  return 0;
}

