#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,i,j,c,d,an=0,k,mod;
    mod=1000000007;
    cin>>n;
    ll ar[n+2];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<60;i++)
    {
        k=(1LL<<i);
        c=0;
        d=0;
        for(j=0;j<n;j++)
        {
            if((ar[j] & k)==0)
                c++;
            else
                d++;
        }
        an=an+((k%mod)*((c*d)%mod))%mod;
        an=an%mod;
    }
     cout<<an<<endl;
}
