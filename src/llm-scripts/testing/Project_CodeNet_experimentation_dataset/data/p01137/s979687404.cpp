#include <iostream>
using namespace std;

int main(){
  while(1){
    int E;
    cin >> E;
    if(E==0) break;
    int x=0,y=0,z=0;
    int m = 1000000;
    for(z=0;z*z*z<=E;z++){
      for(y=0;(z*z*z)+(y*y)<=E;y++){
	x=E-(z*z*z)-(y*y);
	if(x+y+z<m){
	  m=x+y+z;
	  //cout << x << y << z << endl;
	}
      }
    }
    cout << m << endl;	
  }
  
}