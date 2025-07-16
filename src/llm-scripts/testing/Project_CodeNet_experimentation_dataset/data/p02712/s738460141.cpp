#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long x){
  long long y = x / n;
  if(x < n){
    return 0;
  } else {
    return y * (n + y * n) / 2;
  }
}

int main(void){
  long long n;
  cin >> n;
  cout << f(1,n) - f(3,n) - f(5,n) + f(15,n) << endl;
  return 0;
}
