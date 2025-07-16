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

const int MAX_N = 300;

int dp[MAX_N+1][MAX_N+1][MAX_N+1];

const int MOD = 998244353;
int madd(int lhs,int rhs){
    int tmp = lhs+rhs;
    return tmp>=MOD ? tmp-MOD : tmp;
}
int main(){
    string s;
    cin>>s;
    int K;
    cin>>K;
    int n = s.size();
    vector<int> pack(n+1);
    int sum = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0') sum++;
        else pack[sum]++;
    }
    if(sum==n){
        cout<<1<<endl;
        return 0;
    }

    dp[0][0][min(K,n)]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                if(dp[i][j][k]==0) continue;

                for(int x=0;x<pack[i];x++){
                    if(j-(pack[i]-x)>=0) dp[i+1][j-(pack[i]-x)][k] = madd(dp[i+1][j-(pack[i]-x)][k],dp[i][j][k]);
                }
                
                for(int x=pack[i];j+x-pack[i]<=n && k-(x-pack[i])>=0;x++){
                    dp[i+1][j+(x-pack[i])][k-(x-pack[i])] = madd(dp[i+1][j+(x-pack[i])][k-(x-pack[i])],dp[i][j][k]);
                }
            }
        }
    }

    
    int res = 0;
    int pos = n;
    for(int k=0;k<=n;k++){
        res = madd(res,dp[pos][0][k]);
    }
    cout<<res<<endl;

    


    
    
    return 0;
}
