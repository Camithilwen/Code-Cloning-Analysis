#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    str s,t;
    cin>>n>>s>>t;

    int ans=2*n;

    for(int i=n;i>0;i--)
    {
        bool c=true;
        for(int j=0;j<i;j++)if(t[j]!=s[j+n-i]){c=false;break;}
        if(c){ans=n+(n-i);break;}
    }

    cout<<ans<<"\n";

    return 0;
}
