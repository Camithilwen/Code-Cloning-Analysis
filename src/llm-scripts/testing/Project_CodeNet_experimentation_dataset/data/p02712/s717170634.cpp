#include <bits/stdc++.h>
using namespace std;

int main() {
  
  long long n;
  cin >> n;
  
  long long ans = 0;
  
  for(int i = 1; i <= n; i++){
    if(i % 3 == 0 && i % 5 == 0) {
      //FizzBuzz
    } else if(i % 3 == 0) {
      //Fizz
    } else if(i % 5 == 0) {
      //Buzz
    } else {
      ans = ans + i; 
    }
  }
  
  cout << ans;
  
}
