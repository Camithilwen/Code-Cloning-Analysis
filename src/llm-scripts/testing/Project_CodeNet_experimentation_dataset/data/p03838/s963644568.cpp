#include <iostream>
#include <cmath>
using namespace std;

int sign(int x){
  return (x>0)-(x<0);
}
int main(){
  int x,y;
  int count = 0;
  cin >> x >> y;
  
  if( sign(x)*sign(y)==1 ){
    if( x<y ) cout << y-x << endl;
    if( x>y ) cout << x-y+2 << endl;
  }
  if( sign(x)*sign(y)==-1 ){
    if( sign(x)*x<=sign(y)*y ) cout << sign(y)*y-sign(x)*x+1 << endl;
    if( sign(x)*x>sign(y)*y ) cout << sign(x)*x-sign(y)*y+1 << endl;
  }
  if( x*y==0 ){
    if( x<y ) cout << y-x << endl;
    if( x>y ) cout << x-y+1 << endl;
  }
}