#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch[3];
    cin>>ch;

    if(ch[0]=='S')
        {
            if(ch[1]=='U')cout<<"7"<<endl;
            else cout<<"1"<<endl;
        }
    else if(ch[0]=='T')
        {
            if(ch[1]=='U')cout<<"5"<<endl;
            else cout<<"3"<<endl;
        }
    else if(ch[0]=='M')cout<<"6"<<endl;
    else if(ch[0]=='W')cout<<"4"<<endl;
    else cout<<"2"<<endl;

    return 0;
}
