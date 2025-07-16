#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


ll dp[205][100005];

int main(int argc, char* argv[])
{
    long n, x;
    scanf("%ld%ld", &n, &x);

    vector<long> s(n);
    long i,j;
    for(i=0; i<n; i++) {
        scanf("%ld", &s[i]);
    }
    sort(s.rbegin(), s.rend());

    dp[0][x]=1;
    for(i=0; i<n; i++) {
        for(j=0; j<=x; j++) {
            if(dp[i][j]) {
                if(i<n-1) {
                    dp[i+1][j] = (dp[i+1][j] + (dp[i][j]* (n-i-1)))%MOD;
                    dp[i+1][j%s[i]] = (dp[i+1][j%s[i]] + dp[i][j])%MOD;
                }
                else {
                    dp[i+1][j%s[i]] = (dp[i+1][j%s[i]] + dp[i][j])%MOD;
                }
            }
        }
    }

    ll ans=0;
    for(i=0; i<s[n-1]; i++) {
        ans = (ans + i*dp[n][i])%MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
