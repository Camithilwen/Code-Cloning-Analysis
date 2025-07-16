#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  cin >> A >> B >> S;
  string ans="Yes";
  for (int i=0; i<A; i++) {
    if (S[i]=='-') {
      ans="No";
    }
  }
  
  if (S[A]!='-') {
    ans="No";
  }
  
  for (int i=A+1; i<A+B+1; i++) {
    if (S[i]=='-') {
      ans="No";
    }
  }
  
  cout << ans << endl;
  
}
