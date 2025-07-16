#include <bits/stdc++.h>
#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x,y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m)
{
    return power(a, m - 2, m);
}
string find_ans(int n,vector<int>& v,string s)
{
    if(n==1)
    {
        if(v[0]%2==0)
        {
            return s;
        }
        else{
            if(s=="First")
            return "Second";
            else
                return "First";
        }
    }
    int e=0;
    int o=0;
    for(auto c:v)
    {
        if(c%2==0)
            e++;
        else
            o++;
    }
    if(e==1 || e%2!=0)
    {
        return s;
    }
    else if(e%2==0 && o>1){
        if(s=="First")
            return "Second";
        else
            return "First";
    }
    else{
        int g=v[0];
        for(auto &c:v)
        {
            if(c&1)
                c-=1;
        }
        for(auto c:v)
        {
            g=gcd(g,c);
        }
        for(auto &c:v)
        {
            c=c/g;
        }
        if(s=="First")
            s="Second";
        else
            s="First";
        return find_ans(n,v,s);
    }
}
int32_t main()
{
    nitin;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<find_ans(n,v,"First")<<endl;
    return 0;
}