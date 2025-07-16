#include<bits/stdc++.h>
using namespace std;

int main(){
  int prime[10001]={0};

  prime[0]=prime[1]=1;
  for(int i=2;i<sqrt(10000);i++){
    if(!prime[i]){
      for(int j=0;i*(j+2)<10000;j++){
	prime[i*(j+2)]=1;
      }
    }
  }

  int n;
  while(cin>> n,n){
    for(int i=n;i>1;i--){
      if(!prime[i] && !prime[i-2]){
	printf("%d %d\n",i-2,i);
	break;
      }
    }
  }
}