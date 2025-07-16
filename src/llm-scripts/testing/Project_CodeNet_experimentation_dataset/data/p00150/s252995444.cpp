#include <iostream>
#include <cmath>
using namespace std;


bool isprime(int n);

int main(void){
  int n;
  while(1){
    cin>>n;
    if(n==0)break;

    for(int j=n;j>0;j--){
      if(isprime(j) && isprime(j-2)){
        cout<<j-2<<" "<<j<<endl;
        break;
      }
    }
  }
  return 0;
}

bool isprime(int n){
  for(int i=2;i<min((int)sqrt(n)+1,n);i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}

