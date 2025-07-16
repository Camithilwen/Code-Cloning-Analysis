#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int l[10];
  char c;
  while(1){
    for(int i = 0 ; i < 10 ; i++){
      cin >> l[i] >> c;
      if(cin.eof()) return 0;
    }
    int a, b;
    cin >> a >> c >> b;
    
    int n = 0;
    for(int i = 0 ; i < 10 ; i++){
      n += l[i];
    }
    double h = (double)n/(a+b);
    double d = (double)a*h;
    
    n = 0;
    
    for(int i = 0 ; i < 10 ; i++){
      n += l[i];
      if(d <= n){
	cout << i+1 << endl;
	break;
      }
    }
  }
  return 0;
}