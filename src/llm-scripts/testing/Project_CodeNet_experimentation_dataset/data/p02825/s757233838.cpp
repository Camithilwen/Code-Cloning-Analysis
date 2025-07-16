#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,t,cnt[N];bool flag=0;char a[N][N];
int b[4][10][10]={
{
{ 1, 2, 3, 3},

{ 1, 2, 4, 4},

{ 5, 5, 6, 7},

{ 8, 8, 6, 7}
},
{
{ 0, 0, 1, 2, 3},

{ 0, 0, 1, 2, 3},

{ 4, 4, 5, 6, 6},

{ 7, 7, 5, 0, 8},

{ 9, 9,10,10, 8}
},
{
{ 0, 0, 0, 1, 2, 3},

{ 0, 0, 0, 1, 2, 3},

{ 4, 0, 5, 5, 0, 6},

{ 4, 7, 7, 0, 0, 6},

{ 8, 8, 9, 0,10,10},

{11,11, 9,12,12, 0}
},
{
{ 0, 0, 0, 0, 1, 2, 3},

{ 0, 0, 0, 0, 1, 2, 3},

{ 0, 0, 0, 0, 4, 5, 6},

{ 0, 0, 0, 0, 4, 5, 6},

{ 7, 7, 8, 8, 0, 0, 9},

{10,10,11,11, 0, 0, 9},

{12,12,13,13,14,14, 0}
}
};
// void check(){
//     if(!t)return;
//     for(int i=0;i<n;i++){
//         int nn=0;
//         for(int j=0;j<n;j++)
//             if(a[j][i]&&(!j||a[j][i]!=a[j-1][i]))nn++;
//         if(nn!=cnt[0])return;
//     }
//     for(int i=0;i<n;i++){
//         putchar('{');
//         for(int j=0;j<n;j++){printf("%2d",a[i][j]);if(j<n-1)putchar(',');}
//         puts("},\n");
//     }
//     flag=1;
// }
// void dfs(int id){
//     if(flag)return;
//     int x=id/n,y=id%n;
//     if(x&&!y){
//         int xx=x-1;cnt[xx]=0;
//         for(int i=0;i<n;i++)if(a[xx][i]&&(!i||a[xx][i]!=a[xx][i-1]))cnt[xx]++;
//         if(cnt[xx]!=3)return;
//     }
//     if(id==n*n){check();return;}
//     if(a[x][y]){dfs(id+1);return;}
//     dfs(id+1);
//     if(x<n-1&&!a[x+1][y]){
//         t++,a[x][y]=a[x+1][y]=t;
//         dfs(id+1);
//         a[x][y]=a[x+1][y]=0;t--;
//     }
//     if(y<n-1&&!a[x][y+1]){
//         t++,a[x][y]=a[x][y+1]=t;
//         dfs(id+1);
//         a[x][y]=a[x][y+1]=0;t--;
//     }
// }
int main(){
    scanf("%d",&n);
    if(n<3)puts("-1"),exit(0);
    if(n==3)puts("aa.\n..b\n..b"),exit(0);
    int x=(n-4)/4,y=n%4+4;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]='.';
    for(int i=0;i<x;i++)
        for(int j=0,p=i*4;j<4;j++)
            for(int k=0;k<4;k++)
                if(b[0][j][k])
                    a[j+p][k+p]=b[0][j][k]+'a'-1;
    for(int i=0,p=x*4;i<y;i++)
        for(int j=0;j<y;j++)if(b[y-4][i][j])
            a[i+p][j+p]=b[y-4][i][j]+'a';
    for(int i=0;i<n;i++)puts(a[i]);
    return 0;
}