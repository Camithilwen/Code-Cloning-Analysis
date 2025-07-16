#include <bits/stdc++.h>
using namespace std;

int main() {

  int N ; cin >> N ;
  int P ; 
  int a,b,c,d,e,f,g,h ;

  a = N % 10 ;
  b = (N / 10) % 10 ;
  c = (N / 100) % 10 ;
  d = (N / 1000) % 10 ;
  e = (N / 10000) % 10 ;
  f = (N / 100000) % 10 ;
  g = (N / 1000000) % 10 ;
  h = (N / 10000000) % 10 ;

 if ( N % (a+b+c+d+e+f+g+h) == 0 ){
   cout << "Yes" << endl;
  }
 else {
   cout << "No" << endl;
 }
}
