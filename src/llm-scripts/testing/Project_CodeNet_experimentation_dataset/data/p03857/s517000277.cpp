#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define F first
#define S second
#define pb emplace_back
#define mt make_tuple
#define gcd __gcd
#define PI 3.141592653589
// Input
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define llin(a) cin >> a
#define inl(a) scanf("%lld",&a)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
// Output
#define pr(a) printf("%d ",a)
#define pr2(a,b) printf("%d %d\n",a,b)
#define pr3(a,b,c) printf("%d %d %d\n",a,b,c)
#define out(a) printf("%d\n",a)
#define outl(a) printf("%lld\n",a)
#define llpr(a) cout << a << " "
#define llout(a) cout << a << "\n"
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
// Iterator
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define all(vec) vec.begin(),vec.end()
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
// Debug
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define what(x) cerr << #x << " : " << x << "\n"
#define ck printf("continue\n")
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}
// Data Type
#define ll long long int
#define ii pair<int,int>
//#define pli pair<ll,int>
#define triple tuple<int,int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int> >
#define vvii vector<vector<pair<int,int> > >
#define M 1000000007
#define N 200005  //check the limits, man
const ll INF = 1e12;
int par[N],lev[N],tot[N];
void makeset(int n)
{
    fill(par,par+n,-1);
    fill(lev,lev+n,0);
    fill(tot,tot+n,1);
    return;
}
int findset(int x)
{
    int y=x;
    while(par[y]>=0)
        y=par[y];
    if(x!=y)
        par[x]=y;
    return y;
}
void combine(int a,int b)
{
    a=findset(a);
    b=findset(b);
    if(a!=b)
    {
        if(lev[a]<lev[b])
            par[a]=b,tot[b]+=tot[a];
        else if(lev[a]>lev[b])
            par[b]=a,tot[a]+=tot[b];
        else
            lev[b]++,par[a]=b,tot[b]+=tot[a];
    }
    return ;
}
vvi ad(N);
int ar[N];
bool vis[N];
int K;
void dfs(int s)
{
    int i,a,x=ad[s].size();
    vis[s]=1;
    ar[K++]=s;
    rep(i,x)
    {
        a=ad[s][i];
        if(!vis[a])
            dfs(a);
    }
}
int main()
{
    int n,x,y,i,j,a,b;
    in(n);
    in2(x,y);
    while(x--)
    {
        in2(a,b);
        a--,b--;
        ad[a].pb(b);
        ad[b].pb(a);
    }
    makeset(n);
    while(y--)
    {
        in2(a,b);
        combine(a-1,b-1);
    }
    vi v(n);
    vii temp;
    rep(i,n)
    {
        if(!vis[i])
        {
            K=0;
            dfs(i);
            temp.clear();
            rep(j,K)
            {
                a=ar[j];
                b=findset(a);
                temp.pb(b,a);
            }
            sort(all(temp));
            j=0;
            while(j<K)
            {
                a=j;
                while(a<K && temp[j].F==temp[a].F)
                    a++;
                lp(b,j,a)
                    v[temp[b].S]=a-j;
                j=a;
            }
        }
    }
    dbg(v,i,n);
}

