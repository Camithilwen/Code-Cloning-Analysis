#include<iostream>
#include<vector>
using namespace std;

vector<long> dp;
vector<long> pre;

void rec(int i, vector<int>& nottaken, long scoresofar, int mask, int group)
{
  if(i==nottaken.size())
  {
    dp[mask]=max(dp[mask],scoresofar+pre[group]);
    return;
  }
  rec(i+1,nottaken,scoresofar,mask,group);
  rec(i+1,nottaken,scoresofar,mask^(1<<nottaken[i]),group^(1<<nottaken[i]));
  
}


int main(){
  int n;
  cin>>n;
  vector<vector<long>> a(n,vector<long>(n));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  }
  
  pre.resize(1<<n);
  for(int mask=0;mask<(1<<n);mask++)
  {
    for(int i=0;i<n;i++)
    {
      if(mask&(1<<i))
      {
        for(int j=i+1;j<n;j++)
        {
          if(mask&(1<<j))
            pre[mask]+=a[i][j];
        }
      }
    }
  }
  
  
  dp.resize(1<<n,-99999999);
  dp[0]=0;
  for(int mask=0;mask<(1<<n);mask++)
  {
    vector<int> nottaken;
    for(int i=0;i<n;i++)
    {
      if(!(mask&(1<<i)))
         nottaken.push_back(i);
    }
    rec(0,nottaken,dp[mask],mask,0);
  }
  cout<<dp[(1<<n)-1];
  
}