#include <stdio.h>
#include <string.h>

int main(){
    char str1[25];
    char str2[25];
    char str3[25];

    scanf("%s %s %s", str1, str2, str3);

    if (str1[strlen(str1)-1] == str2[0]){
        if (str2[strlen(str2)-1] == str3[0]){
            printf("YES\n");
        }
        else
        {
        printf("NO\n");
        }
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}