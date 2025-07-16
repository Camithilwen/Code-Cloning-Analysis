#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int a[5],k;
for(int i=0;i<5;i++)
{
cin>>a[i];
}
cin>>k;
sort(a,a+5);
string ans="Yay!";
if(a[4]-a[0]>k)
{
ans=":(";
}
cout<<ans<<endl;
}