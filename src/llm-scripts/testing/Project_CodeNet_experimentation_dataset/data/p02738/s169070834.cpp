#include<bits/stdc++.h>

using namespace std;

int N, mod, i2[10009], i3[10009];//[100][100][100];//[270 * 3][270 * 3][270 * 4];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

int fac[2000009], inv[2000009];
void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=0; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){if (K > N || N < 0 || K < 0) return 0; int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &mod), Prec(4 * N + 100);
/*dp[0][0][N] = 1;
for (int i=0; i<3 * N; i++)
{
    int ni = (i + 1) & 1;
    memset (dp[ni], 0, sizeof (dp[ni]));
    for (int j=0; j<=i; j++)
        for (int k=0; k<=4 * N; k++)
            if (dp[i & 1][j][k] > 0)
            {
                ///k = N + cnt1 - cnt2
                ///j = how many numbers smaller than or equal to i i have left
                adto (dp[ni][j + 1][k], dp[i & 1][j][k]);///don't group this one
                if (j >= 2)
                    adto (dp[ni][j - 2][k], mul (dp[i & 1][j][k], j * (j - 1)));
                if (j >= 1 && k > 0)
                    adto (dp[ni][j - 1][k - 1], mul (dp[i & 1][j][k], j));
                adto (dp[ni][j][k + 1], dp[i & 1][j][k]);
            }
}*/
int ans = 0;
//for (int k=N; k<=4 * N; k++)
  //  adto (ans, dp[(3 * N) & 1][0][k]);
i2[0] = i3[0] = 1;
int invv3 = power (3, mod - 2);
for (int i=1; i<=3 * N; i++)
    i2[i] = mul (i2[i - 1], inv[2]),
    i3[i] = mul (i3[i - 1], invv3);
for (int cnt1 = 0; cnt1 <= 3 * N; cnt1 ++)
    for (int cnt2 = 0; cnt2 <= cnt1 && 2 * cnt2 + cnt1 <= 3 * N; cnt2 ++)
        if ((3 * N - cnt1 - 2 * cnt2) % 3 == 0)
        {
            int cnt3 = (3 * N - cnt1 - 2 * cnt2) / 3;
            int curr = mul (mul (fac[3 * N], i2[cnt2]), i3[cnt3]);
            curr = mul (curr, inv[cnt1]), curr = mul (curr, inv[cnt2]), curr = mul (curr, inv[cnt3]);
            //printf ("%d %d %d -> %d\n", cnt1, cnt2, cnt3, curr);
            adto (ans, curr);
        }
printf ("%d\n", ans);
return 0;
}
