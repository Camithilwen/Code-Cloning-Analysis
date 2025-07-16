/* 
 * File:   main.cpp
 * Author: freebsd
 *
 * Created on 2014/08/28, 10:07
 */

#include <cstdio>

using namespace std;

int main() {
    while (true) {
        int n = 0;
        int ice[10] = {0}, icetemp = 0;
        
        scanf("%d", &n);
        
        if(n == 0) break;
        
        for (int i = 0; i < n; i++) {
            icetemp = 0;
            scanf("%d", &icetemp);
            ice[icetemp]++;
        }
        
        for (int i = 0; i < 10; i++) {
            if(ice[i] > 0) {
                for(int j = 0; j < ice[i]; j++){
                    printf("*");
                }
            }else {
                printf("-");
            }
            printf("\n");
        }
        
    }
       
    return 0;
}