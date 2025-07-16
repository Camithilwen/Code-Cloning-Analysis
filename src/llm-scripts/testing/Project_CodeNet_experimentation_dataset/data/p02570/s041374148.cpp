#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=1e6+10;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0') if(ch=='-') d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
int main()
{
    int S,T,V;
    read(S),read(T),read(V);
    if(T*V>=S) puts("Yes");
    else puts("No");
    return 0;
}
