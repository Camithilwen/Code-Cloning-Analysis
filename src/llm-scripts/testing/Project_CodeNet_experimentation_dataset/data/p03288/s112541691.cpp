#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int R ; 
  cin >> R ; 
  
  if(R >=2800){
    cout << "AGC" << endl ; 
  }
  else if(R >=1200 && R < 2800){
    cout << "ARC" << endl ;  
  }
  else {
    cout << "ABC" << endl ; 
  }
}