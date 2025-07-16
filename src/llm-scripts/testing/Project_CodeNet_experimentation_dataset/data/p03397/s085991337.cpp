#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 300003, mod = 1e9 + 7, ch[8][2] = {{3, 1}, {5, 2}, {2, 2}, {4, 7}, {3, 3}, {6, 1}, {5, 5}, {3, 1}};
char str[N];
int n, dp[N][8];
inline void qmo(int &x){x += (x >> 31) & mod;}
int main(){
    scanf("%s", str); n = strlen(str); dp[n][1] = dp[n][2] = 1;
    for(Rint i = n - 1;~i;-- i)
        for(Rint j = 0;j < 8;++ j){
            if(str[i] != '0') dp[i][j] = dp[i + 1][ch[j][1]];
            if(str[i] != '1') qmo(dp[i][j] += dp[i + 1][ch[j][0]] - mod);
        }
    printf("%d\n", dp[0][0]);
}