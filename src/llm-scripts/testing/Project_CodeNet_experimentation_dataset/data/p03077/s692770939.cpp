#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,A,B,C,D,E;;
  cin >> N >> A >> B >> C >> D >> E;
  long slow = min(min(A,B),min(C,min(D,E)));
  cout << (N + slow - 1) / slow + 4 << endl;
}