#include <iostream>
using namespace std;

int getResult(int N, int H, int W){
  int hPattern = N - H + 1;
  int wPattern = N - W + 1;
  if(hPattern <= 0 || wPattern <= 0) return 0;
  return hPattern * wPattern;
}

int main(){
  int N, H, W;
  cin >> N >> H >> W;
  
  int result = getResult(N, H, W);
  cout << result;
  return 0;
}