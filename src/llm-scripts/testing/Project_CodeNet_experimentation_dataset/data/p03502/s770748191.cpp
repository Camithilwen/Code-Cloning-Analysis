#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int f = 0, j = 1; 
  while(N >= (j / 10)){
      j *= 10;
      f += N % j / (j / 10);
  }
  if (N % f == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}