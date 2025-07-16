#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,c1=0,c2=0,c3=0,c=1;
  cin>>n;
  if(n%2==0)
  {
      for(long long int i=1;i<=n/2;i++)
   {
      if(i%3==0 || i%5==0 || i%3==0 && i%5==0)
        continue;
      else
        c1+=i;
   }
   for(long long int j=(n/2)+1;j<=n;j++)
   {
     if(j%3==0 || j%5==0 || j%3==0 && j%5==0)
        continue;
      else
        c2+=j;
   }
   cout<<c1+c2;

  }


  if(n%2!=0)
  {
      for(long long int i=1;i<=n/2;i++)
   {
      if(i%3==0 || i%5==0 || i%3==0 && i%5==0)
        continue;
      else
        c1+=i;
   }
   for(long long int j=(n/2)+1;j<=n;j++)
   {
     if(j%3==0 || j%5==0 || j%3==0 && j%5==0)
        continue;
      else
        c2+=j;
   }
   cout<<c1+c2;

  }
  return 0;



}
