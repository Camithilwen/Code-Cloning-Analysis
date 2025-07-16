#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n+2];
    for(int i=0;i<n;i++)cin>>a[i];
    ll cnt[n+2]={0};
    cnt[0]=a[0];
    for(int i=1;i<n;i++)cnt[i]=cnt[i-1]+a[i];
    ll sum=0;
    ll res=cnt[n-1];
    for(int i=0;i<n-1;i++){
        if(i==0)sum+=(cnt[i]*((res-cnt[i])%mod))%mod;
        else sum+=(((cnt[i]-cnt[i-1])%mod)*((res-cnt[i])%mod))%mod;
    }
    cout<<sum%mod<<endl;
}
