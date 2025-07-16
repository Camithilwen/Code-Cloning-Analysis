#include <bits/stdc++.h>
using namespace std;


int main() {
  int h, w;
  cin >> h >> w;
  
  string s = "";
  string buf(w+2, '.');
  s += buf;
  for (int i = 0; i < h; i++) {
    string si;
    cin >> si;
    s += "." + si + ".";
  }
  s += buf;
  
  
  for (int i = 1; i < h+1; i++) {
    for (int j = 1; j < w+1; j++) {
      if (s.at(i*(w+2)+j) == '#') {
        char sij_up = s.at((i-1)*(w+2)+j);
        char sij_down = s.at((i+1)*(w+2)+j);
        char sij_right = s.at(i*(w+2)+j+1);
        char sij_left = s.at(i*(w+2)+j-1);
        if (sij_up == '.' && sij_down == '.' && sij_right == '.' && sij_left == '.') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  
  cout << "Yes" << endl;
}
