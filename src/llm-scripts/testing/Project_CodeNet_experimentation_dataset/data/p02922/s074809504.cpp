#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,k=1;
  cin >> a >> b;
  for(int i=0;i<100000;i++){
    if(a*i+k-->=b){
      cout << i << endl;
      break;
    }
  }
}
