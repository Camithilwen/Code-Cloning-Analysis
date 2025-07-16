#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s[0]=='S' && s[2]=='N')
        cout<<7-0;
    else if(s[2]=='T')
        cout<<7-6;
    else if(s[0]=='F')
        cout<<7-5;
    else if(s[2]=='U')
        cout<<7-4;
    else if(s[0]=='W')
        cout<<7-3;
    else if(s[2]=='E')
        cout<<7-2;
    else if(s[0]=='M')
        cout<<7-1;

   return 0;
}
