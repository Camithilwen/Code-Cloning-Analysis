#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  if(A>B){
    cout << A+max(A-1,B) << endl;
    return 0;
  }
  cout << B+max(B-1,A) << endl;
}
