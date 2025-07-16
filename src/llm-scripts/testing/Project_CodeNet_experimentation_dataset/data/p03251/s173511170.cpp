#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,m,x,y,z;
  string ans="War";
  cin>>n>>m>>x>>y;
  vector<int> a(n);
  vector<int> b(m);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
  }
  for(int i=0;i<m;i++)
  {
    cin>>b.at(i);
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int i=x+1;i<=y;i++)
  {
    if((a.at(0)<i)&&(b.at(0)>=i))
    {
      ans="No War";
      break;
    }
  }
  cout<<ans<<endl;
}