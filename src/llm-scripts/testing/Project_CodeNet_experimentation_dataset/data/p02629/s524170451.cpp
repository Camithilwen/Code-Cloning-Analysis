#include <stdio.h>
#include <string.h>

int main(){
    
    long long num;
    scanf("%lld", &num);
    char str[100] ={0};
    int i = 0;
    num--;

    while(num >= 0){
         str[i] = num%26 + 'a';
         num /= 26;
        i++;
        num--;                
    }
    int len = strlen(str);
    
    for(int j=len-1;j>=0;j--){
        printf("%c", str[j]);
    }    

    return 0;
}