#include <bits/stdc++.h>
using namespace std;

int main () {
  int A, B;
  cin >> A >> B;

  int tasu = A + B;
  int hiku = A - B;
  int kake = A * B;

  if (tasu >= hiku && tasu >= kake) {
    cout << tasu << endl;
  }
  else if (hiku >= kake && hiku >= tasu) {
    cout << hiku << endl;
  }
  else {
    cout << kake << endl;
  }
}
