#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (ll i = 0; i < n; i++)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const ll MX = 300005;
const ll inf = 2e18;

#define ptr nodo*
#define tam 1234
char resp[tam][tam];
int main () 
{
    vector<string> v4;
    v4.pb("bbio");
    v4.pb("ppio");
    v4.pb("omqq");
    v4.pb("omcc");
    vector<string> v5;
    v5.pb("..cnk");
    v5.pb("..cnk");
    v5.pb("bbuuq");
    v5.pb("mmi.q");
    v5.pb("qqibb");    
    vector<string> v6;
    v6.pb("..cctr");
    v6.pb("...ktr");
    v6.pb("..ck.h");
    v6.pb("bbc..h");
    v6.pb("mmf.gg");
    v6.pb("qqfee.");

    vector<string> v7;
    v7.pb("....gca");
    v7.pb("....gca");
    v7.pb("....vks");
    v7.pb("....vks");
    v7.pb("bbaa.jj");
    v7.pb("mmzzf..");
    v7.pb("qqoof..");
    vector<vector<string> > vvs;
    vvs.pb(v4);
    vvs.pb(v5);
    vvs.pb(v6);
    vvs.pb(v7);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int N=n;
    if (n==2)
        cout<<"-1";
    else
    {
        if (n==3)
        cout<<"a..\na..\n.bb\n";
        else
        {
            forr(i,0,n)
            forr(j,0,n)
            resp[i][j]='.';
            int x,y;
            x=y=0;
            while(n>7)
            {
                forr(i,0,4)
                forr(j,0,4)
                resp[y+i][x+j]=v4[i][j];
                x+=4,y+=4;
                n-=4;
            }
            n-=4;
            int m=vvs[n].size();
                forr(i,0,m)
                forr(j,0,m)
                resp[y+i][x+j]=vvs[n][i][j];
            forr(i,0,N)
            {
                forr(j,0,N)
                cout<<resp[i][j];
                cout<<endl;
            }
        }
    }
   
}