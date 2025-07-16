#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll inf = -1e16;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    ll dp[3];
    rep(i,N) cin >> v[i];

    dp[0] = v[0];
    dp[1] = max(v[0],v[1]);
    if(N>2){
        dp[0] += v[2];
        dp[2] = max(dp[1],(ll)v[2]);
    }
    for(int i=3; i<N; ++i){
        ll tmp1,tmp2;
        tmp1 = dp[0];
        tmp2 = dp[1];
        if((i+1)%2){ // odd
            dp[0] += v[i];
            dp[1] = tmp1> tmp2? tmp1:tmp2 ;
            dp[2] += v[i];
            dp[2] = dp[1]>dp[2]? dp[1]:dp[2];
        }
        else{
            dp[1] += v[i];
            dp[2] = tmp2> dp[2]? tmp2:dp[2] ;
        }
    }

    if(N%2){
        cout << dp[2] << endl;
    }else{
        cout << dp[1] << endl;
    }

    return 0;
}
