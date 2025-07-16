#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+500;
int n;char st[N];
int nxt[N];
int main()
{
    scanf("%d",&n);
    scanf("%s",st+1);scanf("%s",st+n+1);
    for(int i=1;i<=n;i++)swap(st[i],st[i+n]);
    int j=0;
    for(int i=2;i<=2*n;i++)
    {
        while(j&&st[j+1]!=st[i])j=nxt[j];
        if(st[j+1]==st[i])++j;
        nxt[i]=j;
    }
    int t=nxt[2*n];while(t>n)t=nxt[t];
    cout<<2*n-t<<endl;
}