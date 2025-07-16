#include <stdio.h>

#define ICES 10

int main(){
    int num[ICES];
    int n, tmp;

    while (scanf("%d",&n), n!=0){
        for (int i=0; i<ICES; i++) num[i]=0;
        for (int i=0; i<n; i++){
            scanf("%d", &tmp);
            num[tmp]++;
        }
        for (int i=0; i<ICES; i++){
            if (num[i]==0){
                printf("-\n");
            } else {
                for (int j=0; j<num[i]; j++){
                    printf("*");
                }
                printf("\n");
            }
        }
    }    
    return 0;
}