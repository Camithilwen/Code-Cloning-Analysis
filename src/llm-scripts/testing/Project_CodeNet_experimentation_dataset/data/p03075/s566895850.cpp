#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >> k;
  bool x = true;
  
  if( e-a>k || e-b>k || e-c>k || e-d>k || d-a>k || d-b>k || d-c>k || c-a>k || c-b>k || b-a>k ){
  
    x = false;
    
  }
  
  if( x ){
    
    cout << "Yay!" << endl;
    
  }
  
  else{
    
    cout << ":(" << endl;
    
  }
  
}
