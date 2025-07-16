#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0,cnt=0;
    string s;
    cin>>a>>b;
    cin>>s;
    for(int i=0; i<a; i++)
    {
        if(s[i]-'0'<0||s[i]-'0'>9)
        {
            cout<<"No";
                return 0;
        }
    }
    if(s[a]!='-')
    {
        cout<<"No";
            return 0;
    }
    for(int i= a+1 ; i <a+b+1 ; i++)
    {
        if(s[i]-'0'<0||s[i]-'0'>9)
        {
            cout<<"No";
                return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

