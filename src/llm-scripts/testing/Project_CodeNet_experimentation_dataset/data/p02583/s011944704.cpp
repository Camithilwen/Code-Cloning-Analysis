#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long i,j,k,a,b,c=0,n,t;
 cin>>n;
 long long A[n];
 for(i=0;i<n;i++)
 cin>>A[i];
 sort(A,A+n);
 for(i=0;i+2<n;i++)
 {
   for(j=i+1;j+1<n;j++)
   {
     for(k=j+1;k<n;k++)
     {
       if(A[i]!=A[j]&&A[j]!=A[k]&&A[k]!=A[i]&&A[i]+A[j]>A[k]) c++;
     }
   }
 }
 cout<<c<<endl;
return 0;
}
