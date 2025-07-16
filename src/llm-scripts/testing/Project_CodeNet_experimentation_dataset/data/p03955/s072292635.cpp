#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e5; 

int n, a[4][maxn + 5], p[maxn + 5], num[2]; 

int main() {
    scanf("%d", &n); 
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]); 
            if (i == 2) {
                p[j] = (a[i][j] + 1) / 3;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (abs(a[1][i] - a[3][i]) != 2 || abs(a[1][i] - a[2][i]) != 1 || abs(a[2][i] - a[3][i]) != 1) {
            puts("No"); 
            return 0; 
        }
        if (p[i] % 2 != i % 2) {
            puts("No");
            return 0; 
        }
        int mn = min(a[1][i], a[3][i]), mx = max(a[1][i], a[3][i]); 

        if (mx % 3 != 0 || mn % 3 != 1) {
            puts("No");
            return 0; 
        }
        if (a[1][i] % 3 == 0) {
            num[i & 1]++; 
        }
    }
    for (int i = 1; i <= n; i++) {
        while (p[i] != i) {
            num[!(i & 1)]++; swap(p[i], p[p[i]]); 
        }   
    }
    if ((num[0] & 1) or (num[1] & 1)) puts("No");  
    else puts("Yes"); 
    return 0; 
}