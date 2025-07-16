#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;
 
int main()
{
    fast_io
    ll i,j,n,x,ans=0;
    string s;
    bool fA=0,fc=0,noAZ=0;
    cin>>s;
        if(s[0]!='A'||(s[1]>='A'&&s[1]<='Z')||(s[s.length()-1]>='A'&&s[s.length()-1]<='Z'))
   return cout <<"WA"<<endl,0;
    ll cntc=0,cap=0;
    for(i=1; i<s.length()-1; i++)
    {
    if(i>=2&&i<s.length()-1)
    {
        if(s[i]=='C') cntc++;
    }
    if(s[i]>='A'&&s[i]<='Z') cap++;
    }
 
if(cap>1)
   return cout <<"WA"<<endl,0;
    if(cntc!=1)
   return cout <<"WA"<<endl,0;
   return cout <<"AC"<<endl,0;
    return 0;
}
 
 
 