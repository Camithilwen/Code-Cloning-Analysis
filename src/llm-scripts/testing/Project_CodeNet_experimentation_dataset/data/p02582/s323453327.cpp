#include<bits/stdc++.h>
using namespace std;
int main()
{
 char str[3];
 int rain=1,sun=0;
 cin>>str;
 int len = strlen(str);
 for(int i = 0;i<len;i++)
 {
     if(str[i]=='R' && str[i+1]=='R')
     {
         rain++;
     }
     if(str[i]=='S')
     {
         sun++;
     }

 }
 if(rain>1)
 {
 cout<<rain<<endl;
 }
else if(sun==len)
{
    cout<<0<<endl;
}
else
{
    cout<<rain<<endl;
}
    return 0;
}

