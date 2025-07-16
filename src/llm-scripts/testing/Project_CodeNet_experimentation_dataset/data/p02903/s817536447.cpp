#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;

int main()
{
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j<=a)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
    for(int i=b+1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j>a)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
    return 0;
}
