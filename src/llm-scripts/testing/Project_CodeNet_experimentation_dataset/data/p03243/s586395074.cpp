#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, a;
  cin >> N;
  a=(N-N%111)/111;
  if (N%111==0) {
    cout << N << endl;
  }
  else {
    cout << 111*(a+1) << endl;
  }
}