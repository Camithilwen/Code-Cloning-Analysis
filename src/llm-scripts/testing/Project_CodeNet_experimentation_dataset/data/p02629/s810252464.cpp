#include<stdio.h>
int main(){
    long long input;
    scanf("%lld",&input);
    int i = 0;
    char ans[100];
    while(input > 0){
        int temp = input % 26;
        if(temp == 0){
            ans[i++] = 'z';
            input = (input/26) - 1;
        }
        else{
            ans[i++] = (temp - 1) + 'a';
            input = input/26;
        }
    }
    ans[i] = '\0';
    for(int j = i - 1; j >= 0; j--){
        printf("%c",ans[j]);
    }
    return 0;
}