#include<bits/stdc++.h>
using namespace std;
long long sum[200005];
int main()
{
    long long mod=1000000007;
    long long n;cin>>n;long long a[n];long long sum=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        sum=sum%mod;

    }

    long long pum=sum;long long rum=0;
    for(long long i=0;i<n-1;i++)
    {
        //cout<<sum[n-1]<<" "<<sum[i]<<" "<<a[i]<<endl;

       pum=pum-a[i];
       if(pum<0)
        pum+=mod;
       rum+=(a[i]*pum);
       rum=rum%mod;

    }
    cout<<rum;

}
