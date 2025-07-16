#include <bits/stdc++.h>
using namespace std;

map<long long int,long long int>m;
map<long long int,long long int>::iterator it,it1;
main()
{
    long long int n,i,j,k,cnt=0,ans=1;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=n-1;i>0;i--)
    {
        if(a[i]==a[i-1])
        {
            cnt++;
            ans*=a[i];
            i--;
        }
        if(cnt==2)
        {
            break;
        }
    }
    if(cnt==2)
    {
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
