#include <stdio.h>

int main() {
    char str[100];
    scanf("%s", str);
    if (str[3] == '7') {
        str[3] = '8';
    }
    printf("%s\n", str);
    return 0;
}
