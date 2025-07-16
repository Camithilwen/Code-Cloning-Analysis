#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,count=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        string s=to_string(i);
        int n=s.length();
        if(s[0]==s[n-1] && s[1]==s[n-2])
        {
            count++;
        }
        
    }
    cout<<count<<"\n";
    return 0;
}