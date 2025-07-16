#include <stdio.h>
#include <string.h>

int main() {
    char s[11];
    scanf("%s", s);
    if (strlen(s)%2==1) printf("No\n");
    else {
        for (int i=0;s[i]!='\0';i++) {
            if (i%2==0&&s[i]!='h'||i%2==1&&s[i]!='i') {
                printf("No\n");
                return 0;
            }
        }
        printf("Yes\n");
    }
}
