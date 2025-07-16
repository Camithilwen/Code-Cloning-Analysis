#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++)
    cin >> A[i];
  
  bool f = 0;
  
  int count = 0;
  while(1){
  	for (int i = 0; i < N; i++){
       if(A[i] % 2 == 0){
          A[i] = A[i] / 2;
       }else{
         f= 1;
       }
    }
    if(f == 1)
      break;
    count++;
  }
 
  cout << count << endl;
}