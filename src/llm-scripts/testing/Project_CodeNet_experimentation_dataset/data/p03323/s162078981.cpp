#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a(int aa, int b) {
  if(aa <= 8 && b <= 8) {
    return "Yay!";
  }
  return ":(";

}

int main() {
  int aa, b;
  cin >> aa >> b;
  cout << a(aa, b);
}

 