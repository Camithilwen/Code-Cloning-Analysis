#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n;

    map<str,int> a,b;

    for(int i=0;i<n;i++)
    {
        str s;
        cin>>s;

        a[s]++;
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        str s;
        cin>>s;

        b[s]++;
    }

    int ans=0;

    for(auto const& aa:a)
    {
        int cnt=aa.second-b[aa.first];
        if(cnt>0)ans=max(ans,cnt);
    }

    cout<<ans<<"\n";

    return 0;
}
