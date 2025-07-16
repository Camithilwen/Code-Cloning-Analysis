#include<bits/stdc++.h>
#define int long long int
#define mod 998244353 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    #endif
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    int ans=0,s;
    s=a[0];
    for (int i = 1; i < n; ++i)
    {
        s=max(s,a[i]);
        ans+=(s-a[i]);
    }
    cout<<ans;
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       