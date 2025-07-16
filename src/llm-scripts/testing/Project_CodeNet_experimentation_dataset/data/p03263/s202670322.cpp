#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,r,c,i,j,k=0;
    cin>>r>>c;
    int ar[r][c];
    int cn[r*c][4];
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cin>>ar[i][j];
        }
    }
     for(i=0;i<r;i++)
    {
        for(j=0;j<c-1;j++)
        {
            if(ar[i][j]%2!=0)
            {
                k++;
                ar[i][j+1]=ar[i][j+1]+1;
                ar[i][j]=ar[i][j]-1;
             cn[k-1][0]=i;
              cn[k-1][1]=j;
               cn[k-1][2]=i;
                cn[k-1][3]=j+1;
 
 
            }
        }
    }
    for(j=0;j<c;j++)
    {
        for(i=0;i<r-1;i++)
        {
            if(ar[i][j]%2!=0)
            {
                k++;
                ar[i+1][j]=ar[i+1][j]+1;
                ar[i][j]=ar[i][j]-1;
             cn[k-1][0]=i;
              cn[k-1][1]=j;
               cn[k-1][2]=i+1;
                cn[k-1][3]=j;
 
 
            }
        }
    }
    cout<<k<<endl;
    for(i=0;i<k;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j!=3)cout<<cn[i][j]+1<<" ";
          else
            cout<<cn[i][j]+1<<endl;
        }
        //cout<<endl;
    }
 
 
}