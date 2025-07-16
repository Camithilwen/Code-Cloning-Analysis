#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int MOD=1e9+7;
void modplus(int &a,int b){
    a+=b;
    a%=MOD;
}
ll eline(int a){
    if(a<=0)return 1ll;
    vector<vector<int>> dp(a,vector<int>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<a;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    return dp[a-1][0]+dp[a-1][1];
}
int main(){
    int h,w,g;
    cin>>h>>w>>g;
    g--;
    vector<vector<int>> dp(h+1,vector<int>(w,0));
    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int l=-1;l<=1;l++){
                int from=j,to=j+l;
                if(from>to)swap(from,to);
                if(l==0){
                    modplus(dp[i+1][j],dp[i][j]*(eline(from-1)*eline(w-to-2)%MOD)%MOD);
                }else if(0<=j+l&&j+l<w){
                    modplus(dp[i+1][j+l],dp[i][j]*(eline(from-1)*eline(w-to-2)%MOD)%MOD);
                }
            }
        }
    }
    cout<<dp[h][g]<<endl;
}