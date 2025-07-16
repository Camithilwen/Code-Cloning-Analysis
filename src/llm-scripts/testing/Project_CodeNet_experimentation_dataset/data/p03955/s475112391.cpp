#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,t[2],a[5][maxn],to[maxn];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];
    for(int i=1; i<=n; i++)
    {
        to[i]=a[2][i]/3+1;
        if(!((a[1][i]-a[2][i]==-1&&a[2][i]-a[3][i]==-1&&a[1][i]%3==1)||(a[1][i]-a[2][i]==1&&a[2][i]-a[3][i]==1&&!(a[1][i]%3)))||(abs(i-to[i])&1))
        {
            cout<<"No\n";
            return 0;
        }
        if(a[1][i]>a[2][i])
        t[i&1]^=1;
        else t[i&1]^=0;
    }
    for(int i=1;i<=n;i++)
    {
        while(i!=to[i])
        {
            t[i&1^1]^=1;
            swap(to[i],to[to[i]]);

        }
    }

    if(t[0]||t[1]) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}
