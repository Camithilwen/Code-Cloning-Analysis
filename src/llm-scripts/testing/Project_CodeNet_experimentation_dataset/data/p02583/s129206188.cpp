/* Bismillahir Rahmanir Rahim */
#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<string>
#include<stdlib.h>
#define   mod          1000000007
#define   lp(i,a,b)    for(ll i=a;i<=b;i++)
#define   ll           long long int
#define   ull          unsigned long long int
#define   tst          int t;cin>>t;while(t--)
#define   pb           push_back
#define   vi(v)        vector<int>v;
#define   vl(v)        vector<ll>v;
#define   vs           vector<string>v
#define   rslt(x)      cout<<x<<endl;
#define   mp(x,y)      make_pair(x,y)
#define   yes          rslt("YES");
#define   no           cout<<"NO"<<endl;
#define   srt(v)       sort(v.begin(),v.end())
#define   rvs(v)       reverse(v.begin(),v.end());
#define   AR           ios::sync_with_stdio(false);cin.tie(0);
#define   gcd(a,b)     __gcd(a,b)
#define   lcm(a,b)     (a/gcd(a,b))*b
#define   max          1000007
#define   str          int s[200000];
#define   coutv(v)     for(auto it:v)cout<<it<<' ';cout<<endl;
#define   cinv(v)      for(auto &it:v)cin>>it;
using namespace std;
int main()
{
    ll n,x=0;
    str
    cin>>n;
    ll cnt=0;
    lp(i,0,n-1)
    cin>>s[i];
    sort(s,s+n);
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                x=0;
                if(s[i]!=s[j] && s[j]!=s[k])
                {
                    if(s[i]+s[j]>s[k])
                        x++;
                    if(s[i]+s[k]>s[j])
                        x++;
                    if(s[j]+s[k]>s[i])
                        x++;
                    if(x==3)
                        cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;

}

