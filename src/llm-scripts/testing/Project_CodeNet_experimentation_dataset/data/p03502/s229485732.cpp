#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int f = 0;
  cin >> N;
  
  for (int d = 1; d <= N; d*=10){
    f += N/d % 10;
  }

  if (N % f == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}