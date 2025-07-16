#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N , M ; 
  cin >> N >> M ; 
  int max_L = 0 ; 
  int min_R = 5+ 10e5 ; 
  
  for(int i = 0 ; i < M ; i++ ){
    int L , R ; 
    cin >> L >> R ; 
    max_L = max(max_L , L);
    min_R = min(min_R , R);
  }
  min_R++ ; 
  if(min_R > max_L){
  	cout << min_R - max_L << endl ; 
  }
  else{
    cout << 0 << endl ;
  }
  
}