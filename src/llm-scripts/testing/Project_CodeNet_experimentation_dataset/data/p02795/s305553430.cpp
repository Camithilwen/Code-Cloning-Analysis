#include <stdio.h>

int main() {
    int H;
    int W;
    int N;
    scanf("%d", &H);
    scanf("%d", &W);
    scanf("%d", &N);
    int ctr = 0;
    int total = 0;
    while (N > total){
        if(W >= H){
            total += W;
            ctr++;
        }else if(H > W){
            total += H;
            ctr++;
        }
    }
    printf("%d\n",ctr);
    
    return 0;
}