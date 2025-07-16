#include <stdio.h>

int main() {
    int H, W, N;
    
    scanf("%d", &H);
    scanf("%d", &W);
    scanf("%d", &N);
    
    if(W>=H){
    for(int i=1;i<=H;i++){
        if (W*i>=N) {
            printf("%d", i);
            return 0;
        }
    }
} else {
    for(int i=1;i<=W;i++){
        if (H*i>=N) {
            printf("%d", i);
            return 0;
        }
    }
}
    return 0;
}