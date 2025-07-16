#include <iostream>
using namespace std;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  int sum = 0;
  
  if (A <= B && A <= C && A <= D) sum += B + C + D;
  else if (B <= A && B <= C && B <= D) sum += A + C + D;
  else if (C <= A && C <= B && C <= D) sum += A + B + D;
  else sum += A + B + C;

  if (E <= F) sum += F;
  else sum += E;

  cout << sum << endl;

  return 0;
}
