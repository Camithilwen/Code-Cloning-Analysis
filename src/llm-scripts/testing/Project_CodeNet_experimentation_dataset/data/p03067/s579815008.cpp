#include <iostream>
using namespace std;

int main(void){
  int a, b, c;
  cin >> a >> b >> c;
  
  
  cout << ((c-a)*(b-c)>0?"Yes":"No") << endl;
  return 0;
}