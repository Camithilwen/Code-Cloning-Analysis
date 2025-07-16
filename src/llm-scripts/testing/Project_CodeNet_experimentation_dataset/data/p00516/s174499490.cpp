#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  int n,m;
  for(;cin>>n>>m;)
    {
      int a[n];
      for(int i=0;i<n;i++)
	cin>>a[i];
      int cnt[n];
      int ans=0;
      int anscnt=0;
      memset(cnt,0,sizeof(cnt));
      for(int i=0;i<m;i++)
	{
	  int b;
	  cin>>b;
	  for(int j=0;j<n;j++)
	    {
	      if(a[j]<=b)
		{		  
		  cnt[j]++;
		  if(cnt[j]>anscnt)
		    {
		      anscnt=cnt[j];
		      ans=j+1;
		    }
		  break;
		}
	    }
	}
      cout<<ans<<endl;
    }
}