#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    
    while (scanf("%d %d", &n, &q) && n){
        int a[128] = {0};
        
        for (int i = 0; i < n; i++){
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++){
                int x;
                scanf("%d", &x);
                a[x]++;
            }
        }
        
        int mpos = 1;
        
        for (int i = 1; i < 128; i++){
            if (a[i] > a[mpos]) mpos = i;
        }
        
        printf("%d\n", mpos * (a[mpos] >= q));
    }
    
    return (0);
}