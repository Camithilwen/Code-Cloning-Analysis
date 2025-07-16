#include<bits/stdc++.h>
using namespace std ; 

int main(){
  int64_t N ; 
  cin >> N ; 
  int P = N/26 ; 
  vector<char> namae(100)   ;
  int i = 0 ; 
    //cout << N << " " << i << endl ; 
  
  
  while(N != 0 ){
    N-- ; 
    int M = N % 26 ; 
  	namae.at(i)  =  'a' + M ; 
    N  /= 26 ;
    i++ ; 
    
    //cout << N << " " << i << endl ; 
  }
  
  for(int j = i - 1; j >= 0 ; j--){
    cout << namae.at(j) ; 
  }
  
}