#include<bits/stdc++.h>
using namespace std;
long long int Min(long long int x,long long int y)
{
    if(x<y)
        return x;
    return y;
}
int main()
{
    long long int n,k,i,j,x;
    long long int ans;
    cin>>n>>k;
    long long int ara[n];
    for(i=0; i<n; i++)
        cin>>ara[i];

    if(ara[0]<0&&ara[n-1]<=0)
        ans=(-1)*ara[0];
    else if(ara[0]>=0 && ara[n-1]>0)
        ans=ara[n-1];
    else
        ans=(ara[n-1]-ara[0]-ara[0]);

    if(ara[0]>=0)
        cout<<ara[k-1]<<endl;
    else if(k==0)
        cout<<0<<endl;
    else
    {
        for(i=0; i<n; i++)
        {
            j=i+k-1;
            if(j>n-1)
                break;
            if(ara[i]<0 && ara[j]>0){
                    x=Min(ara[j]-ara[i]-ara[i],-ara[i]+ara[j]+ara[j]);
                ans=Min(ans,x);
            }
            else if(ara[i]<0 && ara[j]<=0)
                ans=Min(ans,(-1)*ara[i]);
            else
                ans=Min(ans,ara[j]);
        }
        cout<<ans<<endl;
    }

    return 0;
}
