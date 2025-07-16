#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,s=1;cin>>n>>k;
    for(int i=0;i<n;i++)
        if(s*2<=s+k)
        s*=2;
    else s+=k;
    cout<<s;
    return 0;
   }