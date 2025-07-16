////////////////////////// Author
////////////////////////// Nasim Hossain Rabbi
////////////////////////// JU-CSE28
////////////////////////// CF - imnasim3.1415
////////////////////////// UVA - imnasim3.1415
////////////////////////// Mail - imnasim3.1415@gmail.com
#include<bits/stdc++.h>
using namespace std;
#define E end()
#define B begin()
#define sz size()
#define EM empty()
#define fi first
#define se second
#define cl clear()
#define sqr(a) (a*a)
#define mk make_pair
#define po pop()
#define pu push
#define pb push_back
#define pf push_front
#define pob pop_back()
#define pof pop_front()
string en="\n";
string sp=" ";
string t="hello";
string Y="YES\n";
string N="NO\n";
#define rep(i,n) for(i=0;i<n;i++)
#define Rep(i,n) for(i=1;i<=n;i++)
#define per(i,n) for(i=n-1;i>=0;i--)
#define peR(i,n) for(i=n;i>0;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define all(cont) cont.begin(),cont.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define pi 3.1415926535897932384626433832795
#define vi vector<long long>
#define vs  vector<string>
#define MX LLONG_MAX
#define MN LLONG_MIN
#define MOD 1000000007
#define vp(vi,x) cin>>x; vi.pb(x);
#define bsearch(a,x) binary_search(all(a),x)
#define LB(a,x) (lower_bound(all(a),x)-a.B)
#define UB(a,x) (upper_bound(all(a),x)-a.B)
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
bool isprm(LL a){if(a==1)return false; for(LL i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
bool palin(string a){for(int i=0;i<a.sz;i++){if(a.at(i)!=a.at(a.sz-i-1))return 0;} return 1;}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
LL ceil2(LL a,LL b){LL c=a/b; if(a%b)c++; return c; }
LL bpow(LL a,LL b){if(b==0)return 1;LL r=bpow(a,b/2);if(b%2)return r*r*a;else return r*r;}
LL binpow(LL a,LL b){LL r=1;while(b>0){if(b&1)r=r*a;a=a*a;b>>=1;}return r;}
LL binpow(LL a,LL b,LL m){a%=m;LL r=1;while(b>0){if(b&1) r=r*a%m;a=a*a%m; b>>=1;}return r;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
int main()
{
//    fast;
    LL i,j,k,n,m,l,s=0,x,y,tc=1,p,q,a,b,c=0;
    bool f=0,ff=0;string st,s1,s2,s3; char ch;
    while(cin>>n>>m)
    {
        a=b=0;
        bool ar[n+5];
        rep(i,n+5)ar[i]=0;
        map<LL,LL>mp;
        while(m--)
        {
            cin>>p>>st;
            if(ar[p])continue;
            if(st=="AC") a++,ar[p]=1;
            else mp[p]++;
        }
        for(auto it=mp.B;it!=mp.E;it++)
        {
            if(ar[it->fi])b+=it->se;
        }
        cout<<a<<sp<<b<<en;
    }
    return 0;
}
