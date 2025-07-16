//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
int vis[302][302][302];
double cache[302][302][302];
double dp(int one,int two,int three)
{
    int tot=one+two+three;
    if(!tot)
        return 0;
    if(one<0 || two<0 || three<0)
        return -1;
    if(vis[one][two][three])
        return cache[one][two][three];

    double ans=0;
    double x=n*1.0/(n-(n-tot)*1.0);
    ans=x*((n-tot)*1.0/n + (one*1.0/n)*(1+dp(one-1,two,three))
                +(two*1.0/n)*(1+dp(one+1,two-1,three))
                    +(three*1.0/n)*(1+dp(one,two+1,three-1)));
    vis[one][two][three]=1;
    return cache[one][two][three]=ans;
}
int32_t main() 
{
    IOS;
    cin>>n;
    int freq[4]={};
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        freq[a]++;
    }
    cout<<fixed<<setprecision(12);
    cout<<dp(freq[1],freq[2],freq[3]);
}
