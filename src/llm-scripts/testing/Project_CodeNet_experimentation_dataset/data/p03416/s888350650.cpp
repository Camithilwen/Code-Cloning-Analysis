#include <bits/stdc++.h>
using namespace std;

int main() {

  int A;
  int B;

  cin >> A >> B;

  if (A > B) {
    exit (1);
  }

  if (A < 9999 || B > 100000) {
    exit (1);
  }

  int sum = 0;
  for (int i = A ; i <= B ; i++) {
    string k;
    k = to_string (i);

    int kl = (int)(k.length ());
    string k1 = k.substr (0, (kl - 1)/2);

    string k2 = k.substr ((kl - 1)/2 + 1, kl - 1);

    string k3;
    for (int j = (int)(k2.length ()) - 1 ; j > -1 ; j--) {
      k3 += k2[j];
    }

    // cout << k1 << " : " << k2 << " : " << k3 << endl;
    if (k1 == k3) {
       sum += 1;
    }
  }

  cout << sum << endl;
  
}
