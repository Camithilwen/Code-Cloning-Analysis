#include<bits/stdc++.h>
using namespace std;

int main()
{
   int a , b;
   cin>>a>>b;
int ans =0;
   for(int i=a;i<=b;i++)
   {
       string temp = to_string(i);
       string temp1 = temp;
       reverse(temp1.begin() , temp1.end());
       if( temp == temp1)
           ans++;
   }
cout<<ans;
}