#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
const int N=3e5+2;
ll M=1e9+7;
ll a[N];
int main()
{
    ft
    ll i,j,n,s=0,l,r,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0,m=1;i<61;i++,m*=2)
    {
        l=r=0;
        for(j=0;j<n;j++)
        {
            (a[j]%2)? l++: r++;
            a[j]/=2;
        }
        s+=(((l*r)%M)*(m%M))%M;
        s%=M;
    }
    cout<<s<<"\n";
    return 0;
}