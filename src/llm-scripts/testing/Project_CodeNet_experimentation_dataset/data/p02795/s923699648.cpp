#include <iostream>
#include <math.h>  

using namespace std;

int main() {
  double H, W, N;
  
  cin >> H >> W >> N;
  
  if (H > W) cout << ceil(N/H);
  else cout << ceil(N/W);
  
  return 0;
}