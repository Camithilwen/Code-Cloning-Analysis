#include <bits/stdc++.h>
using namespace std;
 
signed main() {
  int n;
  cin >> n;
  int a[100] = {0};
  double sum;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  int minIndex = 0;
  double avr = sum / n;
  double minDist = abs(avr - a[0]);
  for(int i = 1; i < n; i++){
    if(minDist > abs(avr - a[i])){
      minIndex = i;
      minDist = abs(avr - a[i]);
    }
  }
  cout << minIndex << endl;
}