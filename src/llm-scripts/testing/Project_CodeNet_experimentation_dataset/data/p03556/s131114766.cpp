#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int i = 1;
  while(1) {
    if(i*i>n) break;
    i++;
  }
  cout << (i-1)*(i-1) << endl;
  return 0;
}