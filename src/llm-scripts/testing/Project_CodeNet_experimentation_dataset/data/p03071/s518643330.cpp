#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int a,b,ans;
  cin>>a>>b;
  ans=0;
  ans=ans+max(a,b);
  ans+=max(max(a-1,b-1),min(a,b));
  cout<<ans<<endl;
}
 