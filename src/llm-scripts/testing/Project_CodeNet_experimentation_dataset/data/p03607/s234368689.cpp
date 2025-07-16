#include <bits/stdc++.h>
using namespace std;
int main()
{
long long a,b,i,c=0,d=0,n,m,t,j;
cin>>n;
long long A[n];
for(i=0;i<n;i++)
cin>>A[i];
sort(A,A+n);
for(i=0;i<n-1;i++)
{
  if(A[i]==A[i+1])
  {
    c+=2;
    i++;
  }
}
std::cout <<n-c<< '\n';
return 0;
}
