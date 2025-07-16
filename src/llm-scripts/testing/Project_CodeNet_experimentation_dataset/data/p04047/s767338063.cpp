#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getResult(vector<int> &L, const int size){
  sort(L.begin(), L.end());
  int sum = 0;
  for(int i = 0; i < size; i += 2){
    sum += L[i];
  }
  return sum;
}

int main(){
  int N;
  cin >> N;
  
  const int N2 = N * 2;
  vector<int> L(N2);
  for(int i = 0; i < N2; i++){
    cin >> L[i];
  }

  int result = getResult(L, N2);
  cout << result;
  return 0;
}