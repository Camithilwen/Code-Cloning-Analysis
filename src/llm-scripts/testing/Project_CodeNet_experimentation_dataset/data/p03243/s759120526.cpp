#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p = 1e9, ans = 1e9;
  string bigG;
  cin >> n;
  if(n <= 100 * (n / 100) + 10 * (n / 100) + 1 * (n / 100)){
    cout << 100 * (n / 100) + 10 * (n / 100) + 1 * (n / 100);
  }else{
    cout << 100 * (n / 100 + 1) + 10 * (n / 100 + 1) + 1 * (n / 100 + 1);
  }
  return 0;
}
