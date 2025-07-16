#include <iostream>
#include <stdio.h>
using namespace std;

class Dice{
public:
  int value[6];
  void roll(char _order) {
    switch(_order) {
    case 'N':
      swap(value[4], value[0]);
      swap(value[0], value[1]);
      swap(value[1], value[5]);
      break;
    case 'E':
      swap(value[2], value[0]);
      swap(value[0], value[3]);
      swap(value[3], value[5]);
      break;
    case 'S':
      swap(value[1], value[0]);
      swap(value[0], value[4]);
      swap(value[4], value[5]);
      break;
    case 'W':
      swap(value[0], value[2]);
      swap(value[2], value[5]);
      swap(value[5], value[3]);
      break;
    }
  }
  void rotate(void) {
    this->roll('N');
    this->roll('E');
    this->roll('S');
  }
  bool operator==(const Dice other) {
    bool res = true;
    for (int knock=1;knock<=30;knock++) {
      res = true;
      for (int i=0;i<6;i++)
        if (other.value[i] != this->value[i])
          res = false;
      if (res)
        break;
      else {
        if (knock % 5 == 0) {
          if (knock / 5 <= 3) {
            this->roll('N');
          } else if (knock / 5 == 4) {
            this->roll('E');
          } else {
            this->roll('E');
            this->roll('E');
          }
        } else {
          this->rotate();
        }
      }
    }
    return res;
  }
};

int main() {
  int n;
  Dice dice[100];
  cin >> n;
  for (int i=0;i<n;i++)
    for (int j=0;j<6;j++)
      cin >> dice[i].value[j];

  bool res = true;
  for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
      if (dice[i] == dice[j])
        res = false;

  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

