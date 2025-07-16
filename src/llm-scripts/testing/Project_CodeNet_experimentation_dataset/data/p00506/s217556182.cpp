#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n;
  for(;cin>>n;)
    {
      int data[n];
      int dmax=0;
      for(int i=0;i<n;i++)
	{
	  cin>>data[i];
	  dmax=max(dmax,data[i]);
	}
      for(int i=1;i<=dmax/2;i++)
	{
	  bool flag=true;
	  for(int j=0;j<n;j++)
	    {
	      if(data[j]%i!=0)
		{
		  flag=false;
		  break;
		}
	    }
	  if(flag)
	    cout<<i<<endl;
	}
    }
}