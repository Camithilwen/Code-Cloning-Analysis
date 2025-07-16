#include <stdio.h>

int main() {
    int i, k, v,an1,an2,suu;
    int MAX_V = 10000;
    int prime[MAX_V+1];
    for(i = 0; i <= MAX_V; i++) {
        prime[i] = 1;
    }
    for(i = 2; i*i <= MAX_V; i++) {
        if(prime[i]) {
            for(k = 2 * i; k <= MAX_V; k += i) {
                prime[k] = 0;   
            } 
        }
    }
   while(1){
        scanf("%d",&suu);
        if(suu != 0){
            for(k=2;k<=suu;k++){
            	if(prime[k-2]==1 && prime[k]==1){
        	    	an1=k-2;
        	    	an2=k;
            	}
            }
            printf("%d %d\n",an1,an2);
        }
        else{
    	    break;
        }
    }
    return 0; 
}