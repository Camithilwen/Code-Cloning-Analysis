#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
  	cin>>n>>q;
  	vector<int>a(n);
  	for(int i=0;i<n;i++)cin>>a[i];
  	vector<vector<int> >d(n);
  	vector<int>f(n);
  	vector<int>ans(q);
	vector<vector<int> >id(n);
  	for(int i=0;i<q;i++)
    {
      int l,r;
      cin>>l>>r;
      l--;
      r--;
      d[r].push_back(l);
      id[r].push_back(i);
    }
  	vector<int>p(n+1,-1);
  	for(int i=0;i<n;i++)
    {
      if(p[a[i]]!=-1)
      {
        for(int j=p[a[i]];j<n;j=(j|(j+1)))f[j]-=1;
      }
      p[a[i]]=i;
      for(int j=p[a[i]];j<n;j=(j|(j+1)))f[j]+=1;
  	  for(int j=0;j<d[i].size();j++)
      {
        int lsum=0;
        int rsum=0;
        for(int t=i;t>=0;t=(t&(t+1))-1)rsum+=f[t];
        if(d[i][j]>0)
        {
          for(int t=d[i][j]-1;t>=0;t=(t&(t+1))-1)lsum+=f[t];
        }
        ans[id[i][j]]=rsum-lsum;
      }
    }
  for(auto x:ans)cout<<x<<endl;   
  return 0;
}
     