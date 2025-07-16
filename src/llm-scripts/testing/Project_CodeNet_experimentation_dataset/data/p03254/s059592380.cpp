#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,sum=0;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]<=x&&i<n-1)
            {
                ++ans;
                sum+=a[i];
            }
        else if(sum+a[i]<=x && i==n-1)
        {
            if(sum+a[i]==x)
                ++ans;
        }
        else
           break;

    }
    cout<<ans;
    return 0;
}

