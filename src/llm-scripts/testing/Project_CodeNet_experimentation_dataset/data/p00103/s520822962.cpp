#include<bits/stdc++.h>
using namespace std;
int main(){

  int n;
  string str;
  cin >> n;
  
  for(int i=0;i<n;i++){
    
    int out = 0;
    int a[4] = {};
    
    while(out != 3){
      
      cin >> str;
      
      if(str == "OUT") out++;
      else if(str == "HOMERUN"){
	a[3] += a[0]+a[1]+a[2]+1;
	a[0] = a[1] = a[2] = 0;
      }
      else if(str == "HIT"){
	a[3] += a[2];
	a[2] = 0;
	a[2] = a[1];
	a[1] = 0;
	a[1] = a[0];
	a[0] = 1;
      }
      
    }
    cout << a[3] << endl;
  }
  return (0);
}