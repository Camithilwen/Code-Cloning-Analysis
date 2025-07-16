#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,L;
int result = 0;
  int mini = 10000;
  cin >> N >> L;
  for(int a = 0;a < N;a++){
    result += a + L;
    if(abs(mini) > abs(a + L))mini = a + L;
    
    
    
  }
  cout << result - mini << endl;
}