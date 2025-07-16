#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int M = N;
  int i = 0;
  int sum = 0;
  
  while (M >= 1) {
    sum += (M - (M / 10) * 10);
    M = M / 10;
  }
  
  if (N % sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}