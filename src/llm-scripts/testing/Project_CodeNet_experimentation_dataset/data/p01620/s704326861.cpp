#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    char conv[256];
    int conv2[256];
    
    for (int i = 0; i < 26; i++){
        conv[i] = 'a' + i;
        conv[i + 26] = 'A' + i;
        conv2['a' + i] = i;
        conv2['A' + i] = i + 26;
    }
    
    while (scanf("%d", &n) && n){
        int a[128];
        char s[128];
        
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        
        scanf("%s", s);
        
        for (int i = 0; s[i]; i++){
            printf("%c", conv[(conv2[s[i]] - a[i % n] + 52) % 52]);
        }
        printf("\n");
    }
    
    return (0);
}