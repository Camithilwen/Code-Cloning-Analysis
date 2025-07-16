#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  
  if(a < b){
    if(c >= a && c <= b){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(c >= b && c <= a){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}