#include<bits/stdc++.h>
using namespace std;
int main(){
  char S;
  int mix=0;
  int a=0;
  for(int i=0; i<3;i++){
    cin >> S;
    if (S=='R'){
      a++;
      mix=max(a,mix);
    } else {
      a=0;
    }
  }
  cout << mix << endl;
}