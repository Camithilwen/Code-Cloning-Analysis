#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
 int n,r,k;
  cin>>n>>r;
  k=10;
  if(n<10){k=n;}
  r=r+100*(10-k);
  cout<<r;
  return 0;
}
  