#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0' || '9'<ch)ch=getchar();
    while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();
    return x;
}

const int M=1e5+9;

int m;
int a[M],b[M],top;

int main()
{
    int n=read(),m=read();
    int odd1=-1,odd2=-1;
    for(int i=1;i<=m;i++)
    {
        a[i]=read();
        if(a[i]&1)
        {
            if(odd1==-1)
                odd1=i;
            else if(odd2==-1)
                odd2=i;
            else
            {
                puts("Impossible");
                return 0;
            }
        }
    }

    if(m==1)
    {
        if(a[1]==1)
            printf("1\n1\n1\n");
        else
            printf("%d\n2\n1 %d\n",a[1],a[1]-1);
        return 0;
    }

    if(odd1!=-1)
        swap(a[1],a[odd1]);
    if(odd2!=-1)
        swap(a[m],a[odd2]);

    for(int i=1;i<=m;i++)
        printf("%d%c",a[i]," \n"[i==m]);

    if(a[m]==1)
    {
        printf("%d\n",m-1);
        printf("%d ",a[1]+1);
        for(int i=2;i<m;++i)
            printf("%d ",a[i]);
        puts("");
        return 0;
    }

    b[1]=a[1]+1;
    for(int i=2;i<m;i++)
        b[i]=a[i];
    b[m]=a[m]-1;

    printf("%d\n",m);
    for(int i=1;i<=m;i++)
        printf("%d%c",b[i]," \n"[i==m]);

    return 0;
}