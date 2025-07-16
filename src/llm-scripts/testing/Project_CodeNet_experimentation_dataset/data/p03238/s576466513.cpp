#include <iostream>
using namespace std;

int main(){
  int N;
  
  cin >> N;
  
  if(N == 1) cout << "Hello World" << endl;
  if(N == 2){
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }
  
  return 0;
}