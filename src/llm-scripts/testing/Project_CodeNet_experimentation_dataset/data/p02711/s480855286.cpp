#include<stdio.h> 
int main(){ 
    int r,n,cnt=0;
    scanf("%d",&n);
    while(n>0){
        r=n%10;
        if(r==7){
            printf("Yes");
            cnt++;
            break;
        }
        n=n/10;
         }
    if(cnt==0){
        printf("No");
    }
    
     return 0; 
    }