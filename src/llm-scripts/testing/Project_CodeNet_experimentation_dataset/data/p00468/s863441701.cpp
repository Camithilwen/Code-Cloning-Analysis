#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    while(1)
    {
        int n,m,a[10000],b[10000],lis1[500],lis2[500],x=0,y,z,cnt=0;
        cin>>n>>m;
        if(n==0&&m==0)break;
        for(int i=0;i<m;i++)
        {
            y=0;
            cin>>a[i]>>b[i];
            if(a[i]==1)
            {
                if(x!=0)for(int j=0;j<x;j++)if(lis1[j]==b[i])y++;
                if(y==0)
                {
                    lis1[x]=b[i];
                    x++;
                }
            }
            if(b[1]==1)
            {
                if(x!=0)for(int j=0;j<x;j++)if(lis1[j]==a[i])y++;
                if(y==0)
                {
                    lis1[x]=a[i];
                    x++;
                }
            }
        }
        lis1[x]=1;
        y=0;
        for(int i=0;i<m;i++)
        {
            z=0;
            for(int j=0;j<=x;j++)
            {
                if(a[i]==lis1[j])
                {
                    if(b[i]!=1)
                    {
                        if(y!=0)for(int k=0;k<y;k++)if(lis2[k]==b[i])z++;
                        if(z==0)
                        {
                            lis2[y]=b[i];
                            y++;
                            cnt++;
                        }
                    }
                }
                if(b[i]==lis1[j])
                {
                    if(a[i]!=1)
                    {
                        if(y!=0)for(int k=0;k<y;k++)if(lis2[k]==a[i])z++;
                        if(z==0)
                        {
                            lis2[y]=a[i];
                            y++;
                            cnt++;
                        }
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}