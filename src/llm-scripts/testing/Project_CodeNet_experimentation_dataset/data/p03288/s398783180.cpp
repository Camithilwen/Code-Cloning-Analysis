#include <bits/stdc++.h>
using namespace std;

using pp=pair<int,int>;

int main() {
  int R;
  cin >> R;
  if (R<1200) {
    cout << "ABC" << endl;
  }
  else if (R<2800) {
    cout << "ARC" << endl;
  }else {
    cout << "AGC" << endl;
  }
}