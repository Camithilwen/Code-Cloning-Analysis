#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 2e5 + 20;

#define LL long long

LL n, x;
LL B[maxn], L[maxn], R[maxn];
LL sum[maxn];
LL tsum[maxn];
int rk[maxn];


bool vis[maxn];


int gao(LL score)
{
    LL tot = 0;
    LL les = score % x;
    for(int i = 0; i < n; i++)
    {
        rk[i] = i;
        vis[i] = 0;
        tot -= B[i] * L[i];

        sum[i] = (x - B[i]) * R[i] + B[i] * L[i];

        if(les >= B[i]) tsum[i] = (les - B[i]) * R[i] + B[i] * L[i];
        else tsum[i] = les * L[i];
    }

    sort(rk, rk + n, [](int x, int y){
         if(sum[x] == sum[y]) return tsum[x] < tsum[y];
         return sum[x] > sum[y];
         });

    int k = score / x;
    LL pre = 0;
    for(int i = 0; i < k; i++) pre += sum[rk[i]];

    if(k == n) return tot + pre >= 0;

    LL k1 = sum[rk[k]];

    LL mx = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < k) mx = max(mx, pre - sum[rk[i]] + k1 + tsum[rk[i]]);
        else mx = max(mx, pre + tsum[rk[i]]);
    }

    return tot + mx >= 0;
}

void work()
{
    cin >>n >>x;

    for(int i = 0; i < n; i++)
        cin >>B[i] >>L[i] >>R[i];


    LL l = 0, r = n * x, mid, ans = -1;

    while(l <= r)
    {
        mid = (l + r) / 2;

        if(gao(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout <<ans <<endl;

}

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
#endif // yukihana0416
    work();
    return 0;
}
