#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int h,w,a,b;
    scanf("%d %d %d %d", &h, &w, &a, &b);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if( (2 * i - 2 * b + 1) * (2 * j - 2 * a + 1) > 0){
                printf("%d", 0);
            } else {
                printf("%d", 1);
            }
        }
        printf("\n");
    }
    
    return 0;
}
