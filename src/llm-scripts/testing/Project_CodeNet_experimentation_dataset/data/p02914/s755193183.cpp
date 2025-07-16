#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;

ll n, sum, ans, res;
ll a[N], p[70];

void rd(ll &ans)
{
    ans = 0; ll f = 1;
    char x = getchar();
    while(x > '9' || x < '0') {if(x == '-') f = -1; x = getchar();}
    while(x >= '0' && x <= '9') ans = ans * 10 + x - '0', x = getchar();
    ans *= f;
}

void insert(ll x)
{
    for(int i = 60; ~i; i --)
        if(x & (1LL << i))
        {
            if(p[i]) x ^= p[i];
            else {p[i] = x; break;}
        }
}

int main()
{
    rd(n);
    for(int i = 1; i <= n; i ++) rd(a[i]), sum ^= a[i];
    for(int i = 0; i < 60; i ++)
    {
        if((sum & (1LL << i)) == 0) continue;
        ans += (1LL << i);
        for(int j = 1; j <= n; j ++)
            if(a[j] & (1LL << i)) a[j] ^= (1LL << i);
    }
    for(int i = 1; i <= n; i ++) insert(a[i]);
    for(int i = 60; ~i; i --) res = max(res, res ^ p[i]);
    printf("%lld", ans + (res << 1));
    return 0;
}