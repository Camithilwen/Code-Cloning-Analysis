#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if (A + B > C + D) {
    printf("Left\n");
  } else if (A + B < C + D) {
    printf("Right\n");
  } else {
    printf("Balanced\n");
  }
}