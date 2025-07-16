#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

bool isJudge(lli bit){
    REP(i,0,10){
        if( (bit&(1LL<<i)) && ( bit& (1LL<< (i+1) ) ) )return false;
    }
    return true;
}

lli dp[120][10];

void func(long long H, long long W, long long K){

    dp[0][0]=1;

    REP(i,0,H){
        for(lli bit=0;bit<(1LL<<W);bit++){
            if(!isJudge(bit))continue;
            if((bit&(1LL<<(W-1))))continue;

            REP(j,0,W){
                if((bit&(1LL<<j))){
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= MOD;
                    dp[i+1][j]   += dp[i][j+1];
                    dp[i+1][j]   %= MOD;
                    j++;
                }
                else{
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= MOD;
                }
            }
        }
    }
    cout<<dp[H][K-1]%MOD<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    long long K;
    scanf("%lld",&K);
    func(H, W, K);
    return 0;
}
