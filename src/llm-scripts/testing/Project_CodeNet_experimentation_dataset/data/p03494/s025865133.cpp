#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int n = 1000000000;
  for (int i = 0; i < N; i++){
  		int A;
    cin >> A;
    
	int a = 0;
    
    while ( A % 2 == 0){
      a++;
      A /= 2;
    }
    
	if(n > a)
      n = a;
  }
  
  cout << n << endl;

}
