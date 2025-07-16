#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pii;

#define pb push_back
#define odd(x) ((x)&1)
#define even(x) (!odd(x))
#define ff it->first
#define ss it->second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(auto i=0;i<n;++i)
#define LOOP_IT(it,s) for(auto it=(s).begin();it!=(s).end();++it)
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector<pii> v;

pii fxn(string s)
{
    ll n = s.size();
    ll cnt=0;
    ll x=0,y=0;

    rep(i,n)
    {
        if(s[i]=='(')
            ++cnt;
        else
            --cnt;
        if(cnt<0)
            {++x;cnt=0;}
    }
    y = cnt;

    pii p = {x,y};
    return p;
}

bool cmp1(pii a,pii b)
{
    if(a.first!=b.first)
        return (a.first<b.first);
    return (a.second>b.second);
}
bool cmp2(pii a,pii b)
{
    if(a.second!=b.second)
        return (a.second>b.second);
    return (a.first<b.first);
}

bool chk(vector<pii> &v)
{
    ll sum=0;
    ll n = v.size();
    for(auto p:v)
    {
        sum-=p.first;
        if(sum<0)
        {
            return false;
        }
        sum+=p.second;
    }
    if(sum)
    {
        return false;
    }
    for(ll i=n-1;i>=0;--i)
    {
        pii p = v[i];
        sum+=p.first;
        sum-=p.second;
        if(sum<0)
        {
            return false;
        }
    }
    if(sum)
    {
        return false;
    }
    return true;
}


bool cmp3(pii a,pii b)
{
    ll x = a.second-a.first;
    ll y = b.second-b.first;
    return (x>y);
}


int main(int argv, char* argc[])
{
    FASTIO


    ll n;
    cin>>n;
    string s[n];
    v.resize(n);

    rep(i,n)
    {
        cin>>s[i];
        v[i] = fxn(s[i]);
    }

    sort(all(v),cmp3);
    ll ind =-1;

    for(ll i=0;i<n;++i)
    {
        if(v[i].second-v[i].first<=0)
        {
            ind = i;break;
        }
    }

    if(ind==-1)
        goto label;

    sort(v.begin(),v.begin()+ind,cmp1);
    sort(v.begin()+ind,v.end(),cmp2);
    if(chk(v))
    {
        cout<<"Yes";
        return 0;
    }
    label:
    cout<<"No";





    return 0;
}

