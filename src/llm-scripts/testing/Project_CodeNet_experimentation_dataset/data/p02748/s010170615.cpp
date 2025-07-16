#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main()
{
  int A,B,M;
  cin>>A>>B>>M;
  int a[100010],b[100010],x[100010],y[100010],z[100010];
  rep(i,A)cin>>a[i];
  rep(i,B)cin>>b[i];
  rep(i,M)cin>>x[i]>>y[i]>>z[i];



  int min=200100;
  rep(i,M){
    int sum=0;
    sum+=a[x[i]-1]+b[y[i]-1]-z[i];
    // cout<<sum<<endl;
    if(sum<min)min=sum;
  }
  if(*min_element(a,a+A)+*min_element(b,b+B)<min)min=*min_element(a,a+A)+*min_element(b,b+B);
  cout<<min<<endl;
  return 0;
}
