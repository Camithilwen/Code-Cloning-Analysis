#include<iostream>
using namespace std;

int main() {
  int n;
  int data[3] = {0, 0, 0};

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> data[i];
  }

  for ( int i  = 1; i <= 100000000; i++) {
    if ( data[0] % i == 0 && data[1] % i == 0 && data[2] % i == 0 ) {
      cout << i << endl;
    }
  }

  return (0);
}

