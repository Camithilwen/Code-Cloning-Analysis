#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
string s,p;
int main()
{
    ft
    ll t,i,j,n,m=0,l,r;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if((i+1)<n && s[i]==s[i+1])
        {
            cout<<(i+1)<<" "<<(i+2)<<"\n";
            return 0;
        }
        else if(((i+2)<n && s[i]==s[i+2]))
        {
            cout<<(i+1)<<" "<<(i+3)<<"\n";
            return 0;
        }
    }
    cout<<"-1 -1\n";
    return 0;
}