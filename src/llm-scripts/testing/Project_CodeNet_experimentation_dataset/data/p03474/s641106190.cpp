#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, S;
  cin >> A >> B >> S;
  cout << ((regex_match(S, regex("\\d{" + A + "}-\\d{" + B + "}"))) ? "Yes" : "No") << "\n";
}