#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ll n,i,j,sum=0,x,mn=INT_MAX;
  cin>>n;
  ll ar[n+1],cnt=0;
  for(i=0;i<n;i++)
  {
      cin>>ar[i];
      sum=sum+abs(ar[i]);
      if(ar[i]<0)
      {
          cnt++;
          x=abs(ar[i]);
          if(x<mn)
            mn=x;
      }
      else
      {
           if(ar[i]<mn)
            mn=ar[i];
      }
  }
  if(cnt%2==0)
  {
      cout<<sum<<endl;
  }
  else
  {
      sum=sum-(2*mn);
      cout<<sum<<endl;
  }


}
