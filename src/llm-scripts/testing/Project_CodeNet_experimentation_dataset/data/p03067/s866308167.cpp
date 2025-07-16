#include<iostream>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << ((a-c)*(b-c)<0?"Yes":"No") << endl;
}
