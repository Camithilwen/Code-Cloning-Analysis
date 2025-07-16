#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,a[5],b[5];
    n=2;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    cout<<a[0]+b[0]<<endl;
    return 0;
}
