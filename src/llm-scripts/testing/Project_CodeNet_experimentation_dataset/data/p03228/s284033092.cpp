#include <iostream>
#include <vector>
using namespace std;

void getResult(const uint actCount, uint *cookie1, uint *cookie2){
  uint *first = cookie1;
  uint *second = cookie2;
  for(uint i = 0; i < actCount; i++){
    if(*first % 2 != 0){
      (*first)--;
    }
    uint half = *first / 2;
    *first = half;
    *second += half;
    
    uint *tmp = first;
    first = second;
    second = tmp;
  }
}

int main(){
  uint A, B, K;
  cin >> A >> B >> K;

  getResult(K, &A, &B);
  cout << A << " " << B;
  return 0;
}