#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=998244353;
ll powmod(ll a, ll k){
    ll ap=a, ans=1;
    while(k){
        if(k&1){
            ans*=ap;
            ans%=MOD;
        }
        ap=ap*ap;
        ap%=MOD;
        k>>=1;
    }
    return ans;
}
ll inv(ll a){
    return powmod(a, MOD-2);
}
ll dp[303][303][303];
int main()
{
    string s;
    int k;
    cin>>s>>k;
    s+='0';
    int cnt=0;
    vector<int> v;
    int l=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            v.push_back(cnt);
            cnt=0;
        }else{
            cnt++; l++;
        }
    }
    int m=v.size();
    dp[0][0][0]=1;
    for(int i=0; i<m; i++){
        for(int j=0; j<=l; j++){
            for(int t=0; t<=l; t++){
                if(dp[i][j][t]==0) continue;
                for(int u=max(0, v[i]-t); u<=min({l, l+v[i]-t, l+v[i]-j}); u++){
                    if(u<v[i]){
                        dp[i+1][j][t-(v[i]-u)]+=dp[i][j][t];
                        if(dp[i+1][j][t-(v[i]-u)]>=MOD) dp[i+1][j][t-(v[i]-u)]-=MOD;
                    }else{
                        dp[i+1][j+u-v[i]][t+u-v[i]]+=dp[i][j][t];
                        if(dp[i+1][j+u-v[i]][t+u-v[i]]>=MOD) dp[i+1][j+u-v[i]][t+u-v[i]]-=MOD;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0; i<=min(l, k); i++){
        (ans+=dp[m][i][0])%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
