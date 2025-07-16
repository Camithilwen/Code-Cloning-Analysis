#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}

double n, x; int t;

int main()
{
    // freopen("_in.in", "r", stdin);
    n = read(), x = read(), t = read();
    printf("%d", (int)ceil(n / x) * t);
}