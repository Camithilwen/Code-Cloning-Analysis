#include <bits/stdc++.h>
using namespace std;

int main() {
  int D ;
  int T ;
  int S ;
  
  cin >> D;
  cin >> T;
  cin >> S;
  
  if (T*S < D ) {
    cout << "No" << endl;
  }
  else if (T*S >= D) {
    cout << "Yes" << endl;
  }
}
