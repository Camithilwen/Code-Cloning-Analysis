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
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

ll dp[41][1<<16][2];

int main(int argc, char* argv[])
{
    int n,x,y,z;
    scanf("%d%d%d%d", &n, &x, &y, &z);

    int s=(1<<(x+y+z))+(1<<(y+z))+(1<<z);
    int s2=s/2;

    dp[0][0][0]=1;
    int i,j,p,k;
    for(i=0; i<n; i++) {
        for(j=0; j<(1<<16); j++) {
            for(p=0; p<2; p++) {
                if(dp[i][j][p]) {
                    for(k=1; k<=10; k++) {
                        ll tmp=((ll)((j<<1)+1)<<(k-1));
                        int flag=p;
                        if(flag==0 && (tmp&s2)==s2) {
                            flag=1;
                        }
                        int j2=tmp%(1<<16);
                        dp[i+1][j2][flag]=(dp[i+1][j2][flag]+dp[i][j][p])%MOD;              
                    }
                }
            }
        }
    }
    ll ans=0;
    for(j=0; j<(1<<16); j++) {
        ans=(ans+dp[n][j][1])%MOD;
    }
    printf("%lld\n", ans);

    return 0;
}
