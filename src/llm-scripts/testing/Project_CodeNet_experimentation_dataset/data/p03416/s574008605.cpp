#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  int a=0;
  
  cin >> A >> B;
    
  for(int i=A;i<=B;i++){
    if((i%10==i/10000)&&((i/10)%10==(i/1000)%10)){
      a++;
    }
    else {}
  }
  
  cout << a <<endl;
}