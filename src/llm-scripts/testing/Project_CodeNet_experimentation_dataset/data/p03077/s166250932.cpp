#include<bits/stdc++.h>
using namespace std ; 
const int inf = 1012345678;

int main(){
  int64_t N  ;
  cin >> N ; 
  
  int64_t a , b , c , d , e ; 
  cin >> a >> b >> c >> d >> e ; 
  int64_t min_t = min( a , min( min(b,c),min(d,e) ) ) ; 
  //cout << min_t << endl ;
  
  if(N%min_t ==  0 ){
    cout << N/min_t + 4 << endl ; 
  }
  else{
  	cout << (N/min_t) + 4 + 1 << endl ;
  }

  //975529666566238
}