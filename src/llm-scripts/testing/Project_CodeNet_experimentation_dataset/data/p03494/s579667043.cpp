#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,a,imin,j;
  cin >> N >> A;
  for (imin = 0; A % 2 == 0; imin++)
    A /= 2;
  for (int i = 0;i < N-1; i++) {
    cin >> a;
    for (j = 0;a % 2 == 0;j++)
      a /= 2;
    if (j < imin)
      imin = j;
  }
  cout << imin << endl;     
}