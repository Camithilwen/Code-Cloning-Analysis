#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

char sa[104], sb[104], sc[104], *s;
int ia, ib, ic, *i;
char winner;

int main() {

  cin.getline(sa, 104);
  cin.getline(sb, 104);
  cin.getline(sc, 104);

  s = sa;
  i = &ia;
  while (*i < strlen(s)) {
    *i += 1;
    if (s[(*i)-1] == 'a') {
      s = sa;
      i = &ia;
      winner = 'A';
    } else if (s[(*i)-1] == 'b') {
      s = sb;
      i = &ib;
      winner = 'B';
    } else if (s[(*i)-1] == 'c') {
      s = sc;
      i = &ic;
      winner = 'C';
    }
  }

  cout << winner;
  return 0;
}
