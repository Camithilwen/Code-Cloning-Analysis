#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int N=3e5+30,M=524288;
const int MAX=2e9;
const long long Mod=1e9+7;
int trans[8][2]={{2,1},{4,3},{6,5},{3,3},{7,1},{2,1},{2,2},{4,4}};
long long dp[N][8];
char s[N];
int n;
int main(){
    //freopen("problem.in","r",stdin);
    //freopen("problem.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            if(s[i+1]!='0'){
                dp[i+1][trans[j][1]]+=dp[i][j];
                dp[i+1][trans[j][1]]%=Mod;
            }
            if(s[i+1]!='1'){
                dp[i+1][trans[j][0]]+=dp[i][j];
                dp[i+1][trans[j][0]]%=Mod;
            }
        }
    }
    printf("%lld\n",(dp[n][1]+dp[n][3])%Mod);
    return 0;
}