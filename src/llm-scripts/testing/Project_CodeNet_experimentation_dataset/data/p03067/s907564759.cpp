#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C; cin >> A >> B >> C;
  cout << (((A < C && C < B) || (A > C && C > B)) ? "Yes" : "No") << endl;
}
