#include <stdio.h>

int main()
{
    char op[11];
    int ans[2];

    scanf("%s", op);

    for (int i = 8 ; i <= 9 ; i++){
        ans[i-8] = op[i]-48;
    }

    printf("2018/01/%d%d", ans[0], ans[1]);
    return 0;
}
