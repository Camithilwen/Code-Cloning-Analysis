#include "bits/stdc++.h"
using namespace std;

int main()
{
  int n,ans,mn;
  ans=1;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
  {
    cin>>a.at(i);
  }
  mn=a.at(0);
  for(int i=1;i<n;i++)
  {
    if(mn>a.at(i))
      ans++;
    mn=min(mn,a.at(i));
  }
  cout<<ans<<endl;
}