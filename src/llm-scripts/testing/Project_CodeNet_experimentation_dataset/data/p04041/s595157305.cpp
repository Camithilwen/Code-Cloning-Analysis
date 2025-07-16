#include<iostream>
#include<iomanip>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
#include<memory>
using namespace std;
using ll=long long;

const int SIZE=17;

const int MOD=1e9+7;

inline void add(int &lhs,int rhs){
    lhs=(lhs+rhs);
    if(lhs>=MOD) lhs-=MOD;
}
int dp[41][1<<SIZE];
int isAccept[1<<SIZE];
int mypow10[40];

int main(){
    int n;
    cin>>n;
    int xyz[3];
    for(int i=0;i<3;i++) cin>>xyz[i];

    
    dp[0][(1<<SIZE)-1]=1;

    

    for(int bit=0;bit<(1<<SIZE);bit++){
        int st=0;
        int buf=0;
        for(int i=0;i<SIZE;i++){
            buf++;
            if(!((bit>>i)&1) && xyz[st]==buf){
                st++;
                buf=0;
                if(st==3){
                    isAccept[bit]=true;
                    break;
                }
            }
        }
    }

    
    mypow10[0]=1;
    for(int i=0;i+1<n;i++) mypow10[i+1]=ll(mypow10[i])*10%MOD;

    int res=0;
    int mask=(1<<SIZE)-1;
    for(int i=0;i<n;i++){
        res=res*10LL%MOD;
        for(int bit=0;bit<(1<<SIZE);bit++){
            if(dp[i][bit]==0) continue;
            for(int v=1;v<=7;v++){
                int nex=(bit<<v)+(1<<(v-1))-1;
                nex&=mask;
                add(dp[i+1][nex],dp[i][bit]);
            }
            add(dp[i+1][mask],dp[i][bit]);
            add(dp[i+1][mask],dp[i][bit]);
            add(dp[i+1][mask],dp[i][bit]);
        }
        for(int bit=0;bit<(1<<SIZE);bit++){
            if(isAccept[bit]){
                add(res,dp[i+1][bit]);
                dp[i+1][bit]=0;
            }
        }
    }

    cout<<res<<endl;
    
    
    return 0;
}
