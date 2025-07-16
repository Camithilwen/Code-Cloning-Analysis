#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  for(int i=0;i<9;i++){
    int A=100*(i+1)+10*(i+1)+i+1;
    if(N<=A){
      cout << A << endl;
      break;
    }
  }
}
  