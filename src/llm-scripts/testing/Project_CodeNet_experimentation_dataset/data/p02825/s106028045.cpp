#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1100;
const ll Mod=1000000007;


char ans3[12][12] = {"aa.",
                     "..a",
                     "..a"};
char ans4[12][12] = {"aacd",
                     "bbcd",
                     "dcaa",
                     "dcbb"};
char ans5[12][12] = {"aabc.",
                     "..bcd",
                     "iij.d",
                     "n.jaa",
                     "nkkbb"};
 
char ans7[12][12] = {"aade...",
                     "bbde...",
                     "ccffg..",
                     "..i.gee",
                     "..ihhdd",
                     "....cba",
                     "....cba"};
 
int n;
char a[maxn][maxn];

void add(int st,int len,char (*T)[12])
{
    int x,y;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            x=st+i;
            y=st+j;
            a[x][y]=T[i][j];
        }
    }
}

int main()
{
    sync;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            a[i][j]='.';
    }
    if(n<=2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n==3)
        add(0,3,ans3);
    else if(n==4)
        add(0,4,ans4);
    else if(n==5)
        add(0,5,ans5);
    else if(n==7)
        add(0,7,ans7);
    else if(n==11)
    {
        add(0,4,ans4);
        add(4,7,ans7);
    }
    else if(n%3==0)
    {
        for(int i=0;i<=n;i+=3)
            add(i,3,ans3);
    }
    else
    {
        if(n%5==0)
        {
            for(int i=0;i<=n;i+=5)
                add(i,5,ans5);
        }
        else if(n%5==1)
        {
            add(0,4,ans4);
            add(4,7,ans7);
            for(int i=11;i<=n;i+=5)
            add(i,5,ans5);
        }
        else if(n%5==2)
        {
            add(0,7,ans7);
            for(int i=7;i<=n;i+=5)
            add(i,5,ans5);
        }
        else if(n%5==3)
        {
            add(0,4,ans4);
            add(4,4,ans4);
            for(int i=8;i<=n;i+=5)
            add(i,5,ans5);
        }
        else if(n%5==4)
        {
            add(0,4,ans4);
            for(int i=4;i<=n;i+=5)
            add(i,5,ans5);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
    
}
