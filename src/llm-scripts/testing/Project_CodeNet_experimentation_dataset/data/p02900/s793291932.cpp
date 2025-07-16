#include<bits/stdc++.h>
using namespace std;
long long a,b,i,A,B;int x;
map<int,int>m;
int main()
{
    cin>>A>>B;
    a=A;b=B;
    for(i=2;i*i<=A;i++)
    {while(a%i==0){a/=i;m[i]=1;}}
    if(a!=1)m[a]=1;
    for(i=2;i*i<=B;i++)
    {while(b%i==0){b/=i;if(m[i]==1){x++;m[i]=2;}}}
    if(b!=1){if(m[b]==1)x++;}
    cout<<x+1;
}
