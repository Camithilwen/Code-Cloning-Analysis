#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

int n , g , p[11] , c[11] , mn=1e9;
bool vis[11];

void solve(int i , int sum , int cnt)
{
    if (i > n)
    {
        int rem = g-sum;
        if (rem <= 0) mn = min(mn , cnt);
        else
        {
            for(int j=n; j>0; j--)
            {
                if (vis[j]) continue;
                for(int k=1; k<=p[j]; k++)
                {
                    rem -= j*100 , cnt++;
                    if (rem <= 0)
                    {
                        mn = min(mn , cnt);
                        return;
                    }
                }
            }
        }
        return;
    }

    vis[i] = 1;
    solve(i+1 , sum+p[i]*i*100+c[i] , cnt+p[i]);
    vis[i] = 0;
    solve(i+1 , sum , cnt);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> g;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i] >> c[i];
    }

    solve(1,0,0);
    cout << mn << '\n';

    return 0;
}