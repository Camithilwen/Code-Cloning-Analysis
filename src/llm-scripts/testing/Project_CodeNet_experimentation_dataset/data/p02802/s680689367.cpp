#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{
  int n,m,p[100000],p2[100000],pp,w,a,i;
  string s;
  cin>>n>>m;
  w=0;a=0;
  for(i=0;i<n;i++){p[i]=0;p2[i]=0;}
  
  for(i=0;i<m;i++)
  {
    cin>>pp>>s;
    if(p2[pp-1]==0&&s=="WA"){p[pp-1]++;}
    if(p2[pp-1]==0&&s=="AC"){a++;p2[pp-1]=1;}
  }
  for(i=0;i<n;i++)
  {
  if(p2[i]==1){w+=p[i];}
  }
  cout<<a<<" "<<w;
  return 0;
}