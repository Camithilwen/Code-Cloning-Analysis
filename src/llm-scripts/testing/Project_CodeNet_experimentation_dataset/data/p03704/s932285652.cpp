#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long   ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9;
const double PI = acos(-1);
#define offset 
const ll MOD= 1e9+7;
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 223455
ll D;
ll m;
map<ll,ll> ways;
ll vexp[tam],pot[tam];
ll f(ll pos,ll D2)
{
    if (pos==m)
    {
        return (D2==D);
    }
    ll formas=0;
    ll maxx=-9,minn=9;
    forr(delt,-9,10)
    {
        if (D2+vexp[pos]*delt<=D)
            maxx=delt;
        if (D2+vexp[pos]*delt>D)
            minn=min(minn,delt);
    }
    formas+=f(pos+1,minn*vexp[pos]+D2)*ways[minn];
    if (maxx!=minn)
    formas+=f(pos+1,maxx*vexp[pos]+D2)*ways[maxx];
    return formas;
}
ll go(ll digs)
{
    m=(digs/2);
    //cout<<digs<<' '<<m<<": ";
    forr(i,0,m)
    {
        vexp[i]=(pot[digs-1-i]-pot[i]);
        //cout<<vexp[i]<<" ";
    }
    //cout<<endl;
    ll total=0;
    forr(i,-9,10)
    {
        total+=f(1,vexp[0]*i)*(ways[i]-1);
        //cout<<total<<" "<<i<<' '<<ways[i]-1<<endl;
    }
    if (digs%2==1)
        total= total*10;
        return total;
}
int  main()
{
    forr(i,0,10)
    {
        forr(j,0,10)
        {
            ways[i-j]++;
        }
    }
    
    pot[0]=1;
    forr(i,1,19)
        pot[i]=pot[i-1]*10;
    cin>>D;
    ll formas=0;
    forr(digs,2,19)
    {
        formas+=go(digs);
        //cout<<formas<<'\n';
    }
    cout<<formas<<endl;
}
// PLUS ULTRA!ac