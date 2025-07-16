#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  if(N%10 == 7||N%100 == 70||N%100 == 71||N%100 == 72||N%100 == 73||N%100 == 74||N%100 == 75||N%100 == 76||N%100 == 78||N%100 == 79||N/100 == 7){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}