#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int mod = 1e9 + 7;
const int MaxN = 3e5 + 10;

char s[MaxN];
ll n, f[MaxN][3][3];
void add(ll &a, ll b) {a += b, ((a > mod) ? (a -= mod) : 0); }

int main()
{   
    f[0][0][0] = 1;
    scanf("%s", s + 1), n = strlen(s + 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(s[i + 1] != '0')
                {
                    if(k)
                        add(f[i + 1][j][k - 1], f[i][j][k]);
                    else add(f[i + 1][std::min(j + 1, 2)][k], f[i][j][k]);
                }
                if(s[i + 1] != '1')
                {
                    if(k == 2)
                        add(f[i + 1][j][1], f[i][j][k]);
                    else add(f[i + 1][j][k + 1], f[i][j][k]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <= i; j++)
            add(ans, f[n][i][j]);
    printf("%lld\n", ans);
    return 0;
}
