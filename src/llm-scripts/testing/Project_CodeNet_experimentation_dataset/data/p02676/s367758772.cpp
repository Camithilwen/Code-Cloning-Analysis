#include <bits/stdc++.h>
using namespace std;

int main() {
  long K, x;
  string S;
  cin >> K >> S;  
  x = S.size();
  
  if (x > K) S = S.substr(0, K) + "...";

  cout << S << endl;
}