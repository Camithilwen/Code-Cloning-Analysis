#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int m=n;
    int ans=0;

    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;

        if(p<=m)ans++;
        m=min(p,m);
    }

    cout<<ans<<"\n";

    return 0;
}
