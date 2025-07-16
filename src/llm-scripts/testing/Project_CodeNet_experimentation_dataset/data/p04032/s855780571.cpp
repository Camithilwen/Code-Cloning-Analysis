#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string x;
    cin >> x;
    int n = x.length();

    if(n == 2){
        if(x[0] == x[1]){
            printf("1 2");
        }
        else {
            printf("-1 -1");
        }
        return 0;
    }
    
    for(int i = 0; i < n-2; i++){
        if(x[i] == x[i + 1] || x[i + 1] == x[i + 2] || x[i + 2] == x[i]){
            printf("%d %d", i+1, i+3);
            return 0;
        }
    }
    printf("-1 -1");
    
    return 0;
}
