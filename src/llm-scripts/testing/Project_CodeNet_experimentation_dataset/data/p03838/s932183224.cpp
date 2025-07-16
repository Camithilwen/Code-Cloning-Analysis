#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int sgn(int x){return (x>0)-(x<0);}
int abs(int x){return x>0?x:-x;}
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(!a){if(b>=0)cout<<b<<endl;else cout<<1-b<<endl;return 0;}
    if(!b){if(a>0)cout<<a+1<<endl;else cout<<-a<<endl;return 0;}
    int ans=abs(abs(a)-abs(b));
    if(sgn(a)!=sgn(b))cout<<ans+1<<endl;
    else
    {
        if(a>b)cout<<ans+2<<endl;
        else cout<<ans<<endl;
    }
}