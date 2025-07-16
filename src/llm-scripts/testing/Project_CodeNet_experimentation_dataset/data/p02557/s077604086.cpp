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
#define inf 0x3f3f3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
int a[N],b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    reverse(b+1,b+n+1);
    vector<int >p,q;
    int val=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
            continue;
        cnt++;
        q.push_back(i);
        val=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(!cnt)
            break;
        if(a[i]==b[i])
            continue;
        if(a[i]!=val&&b[i]!=val)
        {
            cnt--;
            p.push_back(i);
        }

    }
    if(cnt)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<q.size();i++)
    {
        swap(b[q[i]],b[p[i]]);
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;

}
