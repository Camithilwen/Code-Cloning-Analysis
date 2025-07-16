#include <stdio.h>
 
int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    
    if(W >= H){
    for(int i = 1; i <= H; i++) {
        if (W * i >= N) {
            printf("%d", i);
            break;        
			}
    	}
	} 
	else {
    for(int i = 1; i <= W; i++){
        if (H * i >= N) {
            printf("%d", i);
            break;
        	}
   	 	}
	}
    return 0;
}