#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char c[3]={};
    int k,ans=999;
    cin>>s;
    for(int i=0;i<s.size()-2;i++)
    {
        c[0]=s[i];
        c[1]=s[i+1];
        c[2]=s[i+2];
        k=atoi(c);
       // cout<<"k = "<<k<<'\n';
        ans=min(abs(k-753),ans);
    }
    cout<<ans;
    return 0;
}


