#include <iostream>
#include <fstream>
using namespace std;
const int nmax=100005;
int p[nmax],viz[nmax],cyc[nmax],newp[nmax];
long long x[nmax],dif[nmax];
long long k,nr;
int n,i,j,xx,m;
int main()
{
    //freopen("data.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(i=1;i<n;i++)
        dif[i]=(x[i+1]-x[i]),p[i]=i;
    cin>>m>>k;
    for(i=1;i<=m;i++)
    {
        cin>>xx;
        swap(p[xx-1],p[xx]);
    }
    for(i=1;i<n;i++)
        if(!viz[i])
    {
        nr=0;xx=i;
        while(!viz[xx])
        {
            viz[xx]=1;
            cyc[nr++]=xx;
            xx=p[xx];
        }
        long long md=(k)%nr;
        for(j=0;j<nr;j++)
            newp[cyc[j]]=(cyc[(j+md)%nr]);
    }
    for(i=1;i<=n;i++)
    {
        if(i>1)x[i]=x[i-1]+dif[newp[i-1]];
        cout<<x[i]<<'\n';
    }
    return 0;
}
