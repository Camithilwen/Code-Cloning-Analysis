#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 2e5+10;
ll dp[mx],arr[mx];
int main()
{
    ll n ;
    cin>>n;
    ll sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(i%2!=0)
            sum+=arr[i];
        if(i!=1)
        {
            if(i%2!=0)
                dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
            else
                dp[i]=max(dp[i-2]+arr[i],sum);
        }
    }
    cout<<dp[n]<<endl;
}
