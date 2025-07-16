#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool ans=true;
  	if(s.length()%2==1)
    {
      cout<<"No";
      return 0;
    }
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0)
        {
            if(s[i]!='h')
            {
                ans=false;
                break;
            }
        }
        else
        {
            if(s[i]!='i')
            {
                ans=false;
                break;
            }
        }
    }
    if(ans)
        cout<<"Yes";
    else cout<<"No";
}