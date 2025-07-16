#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}
int n, ai, sum = 0, mx = 0;
signed main(){
    n = read(); for(int i = 1; i <= n; i++) ai = read(), mx = max(mx, ai), sum += mx - ai;
    printf("%lld", sum);
}