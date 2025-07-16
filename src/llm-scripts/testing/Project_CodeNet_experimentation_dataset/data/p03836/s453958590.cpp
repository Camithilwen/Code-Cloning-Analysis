#include <bits/stdc++.h>
using namespace std;

int main(){
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  string s;
  int dx = x2 - x1;
  int dy = y2 - y1;
  for(int i=0; i<dy; ++i) s += 'U';
  for(int i=0; i<dx; ++i) s += 'R';
  for(int i=0; i<dy; ++i) s += 'D';
  for(int i=0; i<dx+1; ++i) s += 'L';
  for(int i=0; i<dy+1; ++i) s += 'U';
  for(int i=0; i<dx+1; ++i) s += 'R';
  s += "DR";
  for(int i=0; i<dy+1; ++i) s += 'D';
  for(int i=0; i<dx+1; ++i) s += 'L';
  s += 'U';
  cout << s << endl;
}