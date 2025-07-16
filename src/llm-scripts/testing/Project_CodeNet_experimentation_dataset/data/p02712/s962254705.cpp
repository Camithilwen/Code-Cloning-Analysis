#include <stdio.h>
 
int main(){
    
    long long n, sum = 0;
    scanf("%lld", &n);
    for(long long i = 1 ; i <= n ; i++){
    	if(i%3 != 0 && i%5 != 0){
    		sum+=i;
		}
	}
    printf("%lld\n", sum);
    
    return 0;
}