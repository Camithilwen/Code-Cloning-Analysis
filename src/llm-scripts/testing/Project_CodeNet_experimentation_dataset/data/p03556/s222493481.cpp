#include<bits/stdc++.h>
using namespace std;


int main(){
  long long n;
  cin >> n;
  bool ok=false;
  long long i=1;
  while(!ok){
    if(i*i>n){
      cout << (i-1)*(i-1) << endl;
      ok=true;
    }
    i++;
  }
  return 0;
}
