#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a;
    int dp[n];
    int ans=0;
    for(int i=0;i<n;i++)dp[i]=1e9;
    for(int i=0;i<n;i++){
        cin >> a;
        a *= (-1);
        *upper_bound(dp,dp+n,a)=a;
    }
    cout << lower_bound(dp,dp+n,1e9)-dp;
}