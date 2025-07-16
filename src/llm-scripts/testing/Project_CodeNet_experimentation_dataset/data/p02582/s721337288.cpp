#include <iostream>

using namespace std;

int main()
{
    string S;
    cin>>S;
    char a=S[0]=='R';
     char b=S[1]=='R';
      char c=S[2]=='R';

     if(a&b&c)
     {
         cout<<"3";
     }
     else if(a&b||b&c)
     {
         cout<<"2";
     }
     else if(a|b|c)
     {
         cout<<"1";

     }
     else
     {

    cout<<"0";
     }
    return 0;
    }
