#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,x,y;
    cin>>n>>m>>x>>y;
    int ara[n],bra[m];
    for(i=0;i<n;i++)
        cin>>ara[i];
    for(i=0;i<m;i++)
        cin>>bra[i];
    sort(ara,ara+n);
    sort(bra,bra+m);
    for(i=ara[n-1]+1;i<=bra[0];i++)
    {
        if(i>x && i<=y)
        {
            cout<<"No War"<<endl;
            return 0;
        }
    }
    cout<<"War"<<endl;
    return 0;
}
