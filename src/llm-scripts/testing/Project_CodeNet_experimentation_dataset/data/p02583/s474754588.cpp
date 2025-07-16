#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

bool check(int a,int b,int c)
{
    if((a+b)>c && (c+b)>a && (a+c)>b)
        return true;
    return false;
}

int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    int n;
    cin>>n;
    map<ll int,int> mp;
    ll int a;
    int l,ct=0;
    for(l=0;l<n;l++)
    {
        cin>>a;
        mp[a]++;
    }
    
    if(mp.size()<3)
    {
        cout<<0;
        return 0;
    }

    for(auto i=mp.begin();next(next(i))!=mp.end();i++)
    {
        for(auto j=next(i);next(j)!=mp.end();j++)
        {
            for(auto k=next(j);k!=mp.end();k++)
            {
                if(check(i->first,j->first,k->first))
                    ct+=(i->second*j->second*k->second);
            }
        }
    }

    cout<<ct;
    return 0;
}