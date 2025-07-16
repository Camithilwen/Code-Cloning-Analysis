#include <stdio.h>
#define MAX 10000

int main(void){
    int list[MAX]={0}, q;
    
    // determine primes
    for (int i=2; i<MAX; i++){
        if (list[i]==-1) continue;
        list[i]=1;
        for (int j=2*i; j<MAX; j+=i){
            list[j] = -1;
        }
    }
    
    while (scanf("%d",&q),q){
        for (int i=q; i>=5; i--){
            if (list[i]==1 && list[i-2]==1){
                printf("%d %d\n",i-2, i);
                break;
            }
        }
    }
    
    return 0;
}