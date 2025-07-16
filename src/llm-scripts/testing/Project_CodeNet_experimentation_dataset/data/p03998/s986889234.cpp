#include <iostream>
#include <string>
using namespace std;

int next_turn(char c) {
  return int(c) - int('a');
}

int main()
{
  string S[3];
  cin >> S[0] >> S[1] >> S[2];
  int pos[3] = {0};
  int turn = 0;
  for (;;) {
    if (pos[turn] >= S[turn].length()) {
      cout << char(int('A')+turn) << endl;
      break;
    }
    int next = next_turn(S[turn][pos[turn]]);
    pos[turn]++;
    turn = next;
  }
  return 0;
}
