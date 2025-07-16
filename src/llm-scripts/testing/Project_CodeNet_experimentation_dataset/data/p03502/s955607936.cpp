#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, n;
  cin >> N;
  n = N;
  for (int i = 0; i < 9; i++) {    
  int x;      
    x += n % 10;
    n /= 10;
    if (i == 8){
  if ( N % x == 0){
    cout << "Yes" << endl;}
  else{
    cout << "No" << endl;}
    }
  }
}