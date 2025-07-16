#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A;
  cin >> A;
  if(A[1]=='A' && A[2]=='C'||A[0]=='A'&& A[1]=='C'||A[2]=='A'&&A[3]=='C'||A[3]=='A'&&A[4]=='C'){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}