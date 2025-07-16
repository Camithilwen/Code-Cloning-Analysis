#include <bits/stdc++.h>
using namespace std;


int main()
{
   int a,b,c;
   int min,max=0;
   cin>>a>>b>>c;

   if(a<=b)
   {
       min = a;
       max = b;
   }
   
   else
   {
     min = b;
     max = a;

   }
  

   if(c>min && c<max)
   cout<<"Yes"<<endl;

   else
   {
     cout<<"No"<<endl;
   }
   
   return 0;
   
}
