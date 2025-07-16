#include<bits/stdc++.h>
using namespace std;
int b[100000];
int main()
{
    int n;
    cin>>n;
    long long int a[n+5];
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    sort(a,a+n);
    int j=0;
    for(int i=1;i<n;i++)
     {
         if(a[i]==a[i-1])
            {
                b[j]=a[i];
                i++;
                j++;
            }
     }
    if(j>=2)
    {
    long long int x=b[j-1],y=b[j-2];
    cout<<x*y<<endl;
    }
    else
    cout<<0<<endl;
}
