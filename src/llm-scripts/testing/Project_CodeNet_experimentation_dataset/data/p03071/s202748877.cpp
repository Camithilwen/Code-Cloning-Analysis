#include<bits/stdc++.h>
using namespace std;
void solveA()
{
  long long a,b,tem;
  cin>>a>>b;
  tem=(a+b);
  if(tem%2==0)
  {
    cout<<tem/2<<endl;
  }
  else
  {
    cout<<"IMPOSSIBLE"<<endl;
  }
}
void solveB()
{
  int n,i,j,count;
  cin>>n;
  int ar[n];
  for(i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  j=1;
  count=0;
  for(i=0;i<n;i++)
  {
    if(ar[i]!=j)
    {
      count++;
    }
    if(count>2)
    {
      cout<<"NO"<<endl;
      return;
    }
    j++;
  }
  cout<<"YES"<<endl;
}
void solveC()
{
  int a,b,x,y;
  cin>>a>>b;
  x=max(a,b);
  y=min(a,b);
  if((x-y)>=2)
  {
    cout<<2*x-1<<endl;
  }
  else
  {
    cout<<x+y<<endl;
  }
}
void solveD()
{
  int n,i,j;
  cin>>n;
  int ar[n];
  for(i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  int count=n;
  for(i=n-1;i>=0;i--)
  {
    for(j=i-1;j>=0;j--)
    {
      if(ar[i]<ar[j])
      {
        count--;
        break;
      }
    }
  }
  cout<<count<<endl;
}
void solveE()
{
  int h,w,x,y,H,W;
  cin>>H>>W;
  cin>>h>>w;
  x=h*W;
  y=(H-h)*w;
  cout<<(H*W)-(x+y)<<endl;
}
void solveF()
{
  int n,m,c,i,j;
  cin>>n>>m>>c;
  int b[m];
  int ar[n][m];
  for(i=0;i<m;i++)
  {
    cin>>b[i];
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      cin>>ar[i][j];
    }
  }
  int count=0;
  int sum;
  for(i=0;i<n;i++)
  {
    sum=0;
    for(j=0;j<m;j++)
    {
      sum=sum+ar[i][j]*b[j];
    }
    if((sum+c)>0)
    {
      count++;
    }
  }
  cout<<count<<endl;
}
void solveG()
{
  
}
int main()
{
 // solveA();
  //solveB();
 solveC();
 //solveD();
 //solveE();
// solveF();
  return 0;
}