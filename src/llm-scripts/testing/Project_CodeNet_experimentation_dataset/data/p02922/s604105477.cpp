#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int a,b;
  cin>>a>>b;
  int start=1;
  b=b-1;
  int ans;
  ans=b/(a-1);
    if(b%(a-1)!=0)ans++;
  cout<<ans<<endl;
}