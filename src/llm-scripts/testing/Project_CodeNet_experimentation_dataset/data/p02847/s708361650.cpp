#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  if(s == "SUN") cout << 7 << endl;
  else if(s == "MON") cout << 6 << endl;
  else if(s == "TUE") cout << 5 << endl;
  else if(s == "WED") cout << 4 << endl;
  else if(s == "THU") cout << 3 << endl;
  else if(s == "FRI") cout << 2 << endl;
  else if(s == "SAT") cout << 1 << endl;
  return 0;
}