#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s ;
    cin>>s;
    bool a[27]={};
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-'a']=true;
    }
    for(int i=0;i<27;i++)
    {
        if (i==26)
            cout<<"None";
        else if(!a[i])
            {
                char c='a';
                c=c+i;
                cout<<c;
               break;
            }
    }
    return 0;
}

