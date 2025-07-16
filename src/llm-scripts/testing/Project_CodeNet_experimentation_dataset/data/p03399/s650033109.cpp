#include<bits/stdc++.h>
using namespace std ;

int main(){
  int a , b , c , d ; 
  cin >> a >> b >> c >> d ; 
  int M = 0 ; 
  
  if(a > b ){
    M += b ;  
  }
  else{
    M =+ a ; 
  }
  
  if(c>d) M += d ; 
  else M += c ; 
  
  cout << M << endl ; 
  
}