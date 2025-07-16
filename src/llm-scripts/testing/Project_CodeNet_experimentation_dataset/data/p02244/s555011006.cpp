#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int k;cin>>k;
  vector<int> x(k);
  vector<int> y(k);
  int i,j;
  rep(i,k)cin>>y[i]>>x[i];
  vector<int> a(8-k);
  rep(i,8-k)a[i]=i;
  vector<int> okx(0);
  vector<int> oky(0);
  rep(i,8)
  {
    rep(j,k)
    {
      if(x[j]==i)break;
      if(j==k-1)okx.emplace_back(i);
    }
  }
  rep(i,8)
  {
    rep(j,k)
    {
      if(y[j]==i)break;
      if(j==k-1)oky.emplace_back(i);
    }
  }
  vector<vector<bool>> put(8,vector<bool>(8,false));
  rep(i,k)put[y[i]][x[i]]=true;
  do
  {
    vector<vector<bool>> ch(8,vector<bool>(8));
    ch=put;
    rep(i,8-k)
    {
      ch[oky[i]][okx[a[i]]]=true;
    }
    int count=0;
    int out=false;
    for(i=0;i<8;i++)
    {
      count=0;
      for(j=0;i-j>=0;j++)
      {
        if(ch[i-j][j])count++;
      }
      if(count>=2)out=true;
    }
    for(i=8;i<=14;i++)
    {
      count=0;
      for(j=i-7;j<8;j++)
      {
        if(ch[i-j][j])count++;
      }
      if(count>=2)out=true;
    }
    for(i=0;i<8;i++)
    {
      count=0;
      for(j=0;j<8-i;j++)
      {
        if(ch[j+i][j])count++;
      }
      if(count>=2)out=true;
    }
    for(i=0;i<8;i++)
    {
      count=0;
      for(j=0;j<8-i;j++)
      {
        if(ch[j][j+i])count++;
      }
      if(count>=2)out=true;
    }
    if(out)continue;
    rep(i,8)
    {
      rep(j,8)
      {
        if(ch[i][j])cout<<'Q';
        else cout<<'.';
      }
      cout<<endl;
    }
  } while (next_permutation(all(a)));
  
}


