#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  
  int dx = tx - sx, dy = ty - sy;
  string ans = "";
  for (int i = 0; i < dx; i++) ans += "R";
  for (int i = 0; i < dy; i++) ans += "U";
  for (int i = 0; i < dx; i++) ans += "L";
  for (int i = 0; i < dy + 1; i++) ans += "D";
  for (int i = 0; i < dx + 1; i++) ans += "R";
  for (int i = 0; i < dy + 1; i++) ans += "U";
  for (int i = 0; i < 1; i++) ans += "LU";
  for (int i = 0; i < dx + 1; i++) ans += "L";
  for (int i = 0; i < dy + 1; i++) ans += "D";
  for (int i = 0; i < 1; i++) ans += "R";
  
  cout << ans << endl;
}