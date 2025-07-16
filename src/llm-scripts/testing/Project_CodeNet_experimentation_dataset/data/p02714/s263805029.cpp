#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
char a[5000];
ll x,y,z;

int main()
{
     int n,k;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
         if(a[i]=='R')
         {
             x++;
         }
         else if(a[i]=='G')
         {
             y++;
         }
         else
         {
             z++;
         }
     }
     ll ans=x*y*z;
     for(int i=0;i*2<n;i++)
     {
         for(int j=0;j+2*i<n;j++)
         {
             if(a[j]!=a[j+i]&&a[j+i]!=a[j+2*i]&&a[j]!=a[j+2*i])
             {
                 ans--;
             }
         }
     }
     cout<<ans<<endl;
    return 0;
}
