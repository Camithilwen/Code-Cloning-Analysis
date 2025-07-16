#include <bits/stdc++.h>
using namespace std;

bool pal(int a)
{

    return true;
}



int main()
{
    int n,m,mn=0,mx;
    cin>>n>>m;
    mx=n+1;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>=mn)
            mn=a;
        if(b<=mx)
            mx=b;
    }
    if(mn>mx)
        cout<<0;
    else
        cout<<mx-mn+1;
    return 0;
}


