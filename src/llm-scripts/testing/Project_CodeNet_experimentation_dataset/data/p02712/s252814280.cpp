#include <stdio.h>


int main() {
    
    long long int N;
    long long int total = 0;
    
    scanf("%lld", &N);
    int i;
    for( i = 1; i <= N; i++){
        if(i % 3 != 0 && i % 5 != 0 ){
            total = total + i;
        }
    }
    
    printf("%lld\n", total);
    
    
    return 0;
}