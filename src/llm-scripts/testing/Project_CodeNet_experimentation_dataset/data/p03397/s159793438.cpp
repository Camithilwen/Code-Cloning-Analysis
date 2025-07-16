#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long int lld;
const lld MAX=300020;
const lld MOD=1000000007;
char s[MAX];
lld n,dp[MAX][4][10],alt[MAX],fin;
int main(){
    scanf(" %s",s);
    n=strlen(s);
    dp[0][3][3]=1;
    alt[n]=1;
    for(lld x=n-1;x>=0;x--) {
        alt[x]=alt[x+1];
        if(s[x]=='?') alt[x]*=2,alt[x]%=MOD;
    }
    for(lld x=0;x<n;x++){
        for(lld a=-2;a<=0;a++){
            for(lld b=-3;b<=3;b++){
                lld p=(s[x]=='0'||s[x]=='?'),q=(s[x]=='1'||s[x]=='?');
                //if(a==-3&&b==-3) prlldf("%d %d\n",p,q);
                if(p){
                    if(b+1-a>=3) dp[x+1][min(a,b-1) +3][b-1 +3]+=dp[x][a +3][b +3],dp[x+1][min(a,b-1) +3][b-1 +3]%=MOD;
                    else dp[x+1][a +3][b+1 +3]+=dp[x][a +3][b +3],dp[x+1][a +3][b+1 +3]%=MOD;
                }
                if(q){
                    if(min(a,b-1)<=-3) fin+=(alt[x+1]*dp[x][a +3][b +3])%MOD,fin%=MOD;
                    else dp[x+1][min(a,b-1) +3][b-1 +3]+=dp[x][a +3][b +3],dp[x+1][min(a,b-1) +3][b-1 +3]%=MOD;
                }
            }
        }
    }
    for(lld a=-2;a<=0;a++){
        for(lld b=-3;b<=0;b++){
            fin+=dp[n][a +3][b +3],fin%=MOD;
        }
    }
    printf("%lld\n",fin);
}
