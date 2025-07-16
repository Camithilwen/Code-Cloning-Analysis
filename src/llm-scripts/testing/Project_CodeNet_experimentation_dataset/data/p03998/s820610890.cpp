#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define M 1000000007
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define f first
#define s second
#define b begin
#define e end
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define itfr(it,x) for(it=x.begin();it!=x.end();it++)
#define flash ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main()
{
    flash;
    //sieve();
    ll T=1,n,m,k,x,y,z;
    // cin>>T;
    while(T--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        n = a.length();
        m = b.length();
        k = c.length();
        x = 0; y = 0; z = 0;
        char cur = 'a';
        while(x<=n&&y<=m&&z<=k)
        {
            if(cur=='a')
            {
                cur = a[x];
                x++;
            }
            else if(cur=='b')
            {
                cur = b[y];
                y++;
            }
            else
            {
                cur = c[z];
                z++;
            }
        }
        if(x>n)
            cout<<'A';
        else if(y>m)
            cout<<'B';
        else
            cout<<'C';
        cout<<endl;
    }
}
