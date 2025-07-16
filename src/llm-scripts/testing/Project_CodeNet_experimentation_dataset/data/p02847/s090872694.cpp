#include<bits/stdc++.h>
using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long i,j,k,l,m,n,o,p;

    string s;

    while(cin>>s)
    {
        if(s[0]=='S'&&s[1]=='A')
            cout<<"1"<<endl;
        else  if(s[0]=='S'&&s[1]=='U')
            cout<<"7"<<endl;
        else  if(s[0]=='M'&&s[1]=='O')
            cout<<"6"<<endl;
        else  if(s[0]=='T'&&s[1]=='U')
            cout<<"5"<<endl;
        else  if(s[0]=='W'&&s[1]=='E')
            cout<<"4"<<endl;
        else  if(s[0]=='T'&&s[1]=='H')
            cout<<"3"<<endl;
        else  if(s[0]=='F'&&s[1]=='R')
            cout<<"2"<<endl;
    }

    return 0;

}
