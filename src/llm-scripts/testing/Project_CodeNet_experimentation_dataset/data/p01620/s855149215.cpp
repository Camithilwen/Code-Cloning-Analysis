#include<cstdio>
#include<algorithm>

using namespace std;

int main(void) {
    char list[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    while(true) {
        int n,k[200];
        char s[150]={};

        scanf("%d", &n);
        if(!n) break;

        for(int i=0; i<n; i++)
            scanf("%d", &k[i]);

        scanf("%s",s);

        for(int i=0; s[i]; i++) {
            printf("%c", list[((lower_bound(list, list+52, s[i])-list)-k[i%n]+52)%52]);
        }
        printf("\n");
    }
    return 0;
}