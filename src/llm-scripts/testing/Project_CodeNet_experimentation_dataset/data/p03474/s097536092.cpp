#include <stdio.h>
#include <string.h>

int main() {
    int A,B;
    char S[20];
    int C, counts = 0;
    scanf("%d %d", &A, &B);
    scanf("%s", S);
    C = strlen(S);
    
    if(!(S[A] == '-')){
        printf("No");
        return 0;
    }
    for(int i=0;i<C;i++){
        if(S[i] == '-'){
            counts++;
        }
    }
    if(counts > 1){
        printf("No");
        return 0;
    }
    
    printf("Yes");
            
return 0;
}