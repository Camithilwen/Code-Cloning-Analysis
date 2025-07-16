#include<bits/stdc++.h>
using namespace std;
int main()
{
   string ch="...";
    int limit;
    while(cin>>limit)
    {
       string str;
       cin>>str;
       int size=str.size();
       if(size==limit || size<limit)
        {
          cout<<str<<'\n';
        }
        else
        {
            string temp;
            for(int i=0;i<limit;i++)
             {
                temp+=str[i];
             }
            temp+=ch;
            cout<<temp<<'\n';
        }
    }
}