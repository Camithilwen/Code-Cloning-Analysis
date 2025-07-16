#include <bits/stdc++.h>
using namespace std;

char S[15];

int main(){
    scanf(" %s", S);

    int len = strlen(S);
    if(len%2 != 0){
        printf("No");
        return 0;
    }
    for(int i = 0; i < len; i ++){
        if(i%2 == 0 && S[i] != 'h'){
            printf("No");
            return 0;
        }
        if(i%2 == 1 && S[i] != 'i'){
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
