#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    int a,b;
    cin>>a>>b;
    string s;
    cin>>s;
    if(s[a]!='-')
    {
        cout<<"No";return;
    }
    for(int i=0;i<a+b+1;i++)
    {   
        if(i!=a && s[i]=='-')
        {
            cout<<"No";return;
        }
    }
    cout<<"Yes";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
