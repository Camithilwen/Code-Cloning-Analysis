#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <queue>

#define INF INT_MAX

using namespace std;

int main()
{
  string s;
  for(;cin>>s;)
    {
      int ans=0,tmp=0;
      int n[]={1000,500,100,50,10,5,1};
      string nn="MDCLXVI";
      for(int i=0;i<s.size();i++)
	{
	  for(int j=0;j<nn.size();j++)
	    {
	      if(s[i]==nn[j])
		{
		  ans+=n[j];
		  if(tmp<n[j])
		    ans-=tmp*2;
		  tmp=n[j];
		}
	    }
	}
      cout<<ans<<endl;
    }
}