#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int sum = 0;
  
  for (int i = A; i <= B; i++) {
    int x = i;
    int n1 = x % 10;
    x = x / 10;
    int n2 = x % 10;
    x = x / 10;
    //int n3 = x % 10;
    x = x / 10;
    int n4 = x % 10;
    x = x / 10;
    int n5 = x;
    
    if (n1 == n5 && n2 == n4) {
      sum++;
    }
  }
  cout << sum << endl;
}
