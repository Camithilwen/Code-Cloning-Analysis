#include<iostream>
using namespace std;
int main (void)
{
  int r;
  cin>>r;
  while(r>1)
  { 

    if(r%10==7)
    {
      cout<<"Yes";return 0;
    }
    r=r/10;
  }
  cout<<"No";
}