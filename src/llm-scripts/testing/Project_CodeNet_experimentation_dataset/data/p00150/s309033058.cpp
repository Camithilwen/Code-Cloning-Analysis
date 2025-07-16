#include <iostream>
#include <memory.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

const int sz = 100000;
bool prime[sz];

int main(){
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for(int i = 2; i * i < sz; i++){
    if(prime[i]){
      for(int j = 2; i * j < sz; j++){
	prime[i*j] = false;
      }
    }
  }
  
  int n;
  while(cin >> n && n){
    for(int i = n; i >= 2; i--){
      if(prime[i] && prime[i-2]){
	cout << i - 2 << " " << i << endl;
	break;
      }
    }
  }
  return 0;
}