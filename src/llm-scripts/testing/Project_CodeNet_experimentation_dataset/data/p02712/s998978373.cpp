#include  <bits/stdc++.h>
using namespace std;
long long sum(long long n)
{return n*(n+1)/2;}
 int main(){
 int n;
 cin>>n;
 long long ans;
 ans=sum(n)-sum(n/3)*3-sum(n/5)*5+sum(n/15)*15;
 cout<<ans;
return 0;
 }
