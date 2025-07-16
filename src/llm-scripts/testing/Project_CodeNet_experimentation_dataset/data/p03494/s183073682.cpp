#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int check = 1000;
  for(int i; i < N; i++){
    int A;
    int count = 0;
    cin >> A;
    while(A % 2 == 0){
      A /= 2;
      count += 1;
    }
    if(count < check){
      check = count;
    }
  }
  cout << check << endl;
}