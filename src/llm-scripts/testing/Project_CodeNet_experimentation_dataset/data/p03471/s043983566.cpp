#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,y;cin>>n>>y;

    int sy=y-n*1000;
    int n1=-1,n5=-1,n10=-1;

    for(int i=0;i<=n;i++)
    {
        int bsy=sy-i*4000;
        if(bsy<0)break;
        if(bsy%9000==0)
        {
            if(bsy/9000+i<=n)
            {
                n10=bsy/9000;
                n5=i;
                n1=n-n10-n5;
                break;
            }
        }
    }

    cout<<n10<<" "<<n5<<" "<<n1<<"\n";

    return 0;
}
