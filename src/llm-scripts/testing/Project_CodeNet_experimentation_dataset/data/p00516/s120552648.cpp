#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  int a[1000]={};
  int b[1000]={};
  int max =0;
  int t;
  int cnt[1000]={};

  cin >> n >> m;

  for(int i=0;i<n;i++)
    {
      cin >> a[i];
    }
  for(int j=0;j<m;j++)
    {
      cin >> b[j];
    }

  for(int j=0;j<m;j++)
    {
      for(int i =0;i<n;i++)
	{
	  
      if(a[i] <= b[j])
	{
	  cnt[i]++;
	  break;
	  /* if(max < a[i])
	    {
	      max = a[i];
	      t=i;
	      }*/
	}
      
	}
      //  cnt[t]++;
    }
  max =0;
  for(int i =0;i<n;i++)
	{
	   if(max < cnt[i])
	    {
	      max = cnt[i];
	      t=i;
            }
	 
	}
  cout << t+1 << endl;
}

