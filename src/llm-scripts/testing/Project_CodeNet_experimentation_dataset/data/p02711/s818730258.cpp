#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int a,b,c;
  a=N/100, b=(N/10)%10, c=N%10;
  
  if (a == 7 || b == 7 || c == 7){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
  return 0;
}