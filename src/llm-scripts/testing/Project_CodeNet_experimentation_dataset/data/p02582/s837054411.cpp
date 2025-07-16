#include <iostream>
using namespace std;

int main(void){
  int cd=0;
  char c;
  
  for (int i=0; i<3; i++){
    cin >> c;
    cd = (cd<<1) | (c=='R'?1:0);
  }
  cout << (cd["01121123"]) << endl;
  return 0;
}