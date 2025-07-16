#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){

    int n;
    cin>>n;
    vector<int> arr(n+1);

    for(int i = 1; i <= n; i++) cin>>arr[i];

    vector<ll> pf(n+1);
    vector<ll> dp(n+1,LLONG_MIN);
    for(int i = 1; i <= n; i++) if(i&1) pf[i]+=arr[i]+pf[i-2 < 0 ? 0 : i-2]; // pref of odd sum

    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        if(i&1) dp[i] = max(dp[i-1],arr[i]+dp[i-2]); // for odd 
        else dp[i] = max(pf[i-1],dp[i-2]+arr[i]); //for even
    }
    cout<<dp[n];
}
