#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int s = 0;
  int M = N;
    while(M != 0){
      s += M % 10;
      M = M / 10;
    }
	if ( N % s == 0)
      cout << "Yes" << endl;
  	if ( N % s != 0)
      cout << "No" <<endl;
}

