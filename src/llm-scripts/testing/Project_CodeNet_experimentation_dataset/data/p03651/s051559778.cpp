#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a,b,c,d,e,f,g,h,i,j,k,l,m,n,t,prothom,boro;
  cin>>n>>k;

   cin>>a;

  boro=a;

  for(int i=1;i<n;i++)
{
    cin>>b;
    a=__gcd(a,b);
    boro=max(boro,b);
}
  if(k<=boro && k%a==0)
    {
    cout<<"POSSIBLE"<<endl;
  }
  else
  {
    cout<<"IMPOSSIBLE"<<endl;
  }

}
