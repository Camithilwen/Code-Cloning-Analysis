#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax];
bool valid(int n) {
  if(0 < v[1])
    return 0;
  for(int i = 2; i <= n; i++) 
    if(v[i - 1] + 1 < v[i])
      return 0;
  return 1;
}
int frec[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  if(valid(n) == 0)
    std::cout << -1;
  else {
    ll result = 0;
    for(int i = n; 1 <= i; i--) {
      if(frec[i - v[i]] == 0) {
        result += v[i];
        frec[i - v[i]] = 1;
      }
    }
    std::cout << result;
  }
  return 0;
}
