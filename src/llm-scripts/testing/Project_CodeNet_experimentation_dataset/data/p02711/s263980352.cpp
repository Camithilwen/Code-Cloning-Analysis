#include<stdio.h>
int main() {
 int N,B;
 scanf("%d",&N);  
 while(N!=0)
 {   
  B=N%10;
 
  if(B==7) {
  printf("Yes");
  break;
  }
  N=N/10;
 }  
  if(B!=7)
  printf("No");    
    
 return 0;
}