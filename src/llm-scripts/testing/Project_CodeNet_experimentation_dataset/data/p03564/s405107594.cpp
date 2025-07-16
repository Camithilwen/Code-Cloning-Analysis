#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,k;
  cin >> N >>k;
  int sum;
  if(k==1){
	sum = N+1;
  }
  else if(k==2||k==3||k==4){
    if (N==1){
      sum = 2;
    }
    else{
    sum = 4 + k*(N-2);
    }
  }
  else if(k==5||k==6||k==7){
    if (N==1){
      sum = 2;
    }
    else if(N==2){
      sum = 4;
    }
    else{
    sum = 8 + k*(N-3);
    }
  }
  else{
    if (N==1){
      sum = 2;
    }
    else if (N==2){
      sum = 4;
    }
    else if (N==3){
      sum = 8;
    }
    else{
    sum = 16 + k*(N-4);
    }
  }
  cout<<sum<<endl;
}
