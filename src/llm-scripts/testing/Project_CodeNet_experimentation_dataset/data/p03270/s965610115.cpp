// ※※※ 解答不能 ※※※
// 解き直し.
// scott_wu氏.
// https://atcoder.jp/contests/arc102/submissions/3114772
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL MOD = 998244353;
const int MAXN = 4100;

int K, N;
LL pascal[MAXN][MAXN];

int main(){

    pascal[0][0] = 1;
    for(int i = 1; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            pascal[i][j] = pascal[i - 1][j];
            if(j) pascal[i][j] = (pascal[i][j] + pascal[i - 1][j - 1]) % MOD;
        }
    }

    scanf("%d %d", &K, &N);
    for(int i = 2; i <= 2 * K; i++){
        int n2 = 0, n1 = 0;
        for(int j = 1; j <= K; j++){
            if(j * 2 == i) continue;
            if((i - j) <= K && (i - j) >= 1) n2++;
            else                             n1++;
        }
        n2 /= 2;
        LL res = 0;
        LL p2 = 1;
        for(int j = 0; j <= n2; j++){
            if(j) p2 = (p2 * 2) % MOD;
            if(j > N) continue;
            if(j == 0 && n1 == 0) continue;
            res = (res + pascal[n2][j] * (p2 * pascal[N + n1 - 1][j + n1 - 1] % MOD)) % MOD;
            if(i % 2 == 0) res = (res + pascal[n2][j] * (p2 * pascal[N+n1-2][j+n1-1] % MOD)) % MOD;
        }
        printf("%lld\n", res);
    }
    
    return 0;

}