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
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
#define mod 998244353
#define N 1000010
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int l=1,r=m+1;
    while(l<r)
    {
        cout<<l++<<" "<<r--<<endl;
    }
    l=m+2,r=2*m+1;
    while(l<r)
    {
        cout<<l++<<" "<<r--<<endl;
    }
    return 0;
}
