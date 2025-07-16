#include <bits/stdc++.h>

using namespace std;

int cnt[80][50];
int cnt2[200100], cnt5[200100];

char str[50];

long long inp()
{
    memset(str, 0, sizeof(str));
    scanf("%s", str);
    long long ret = 0;
    int point = 0;
    int pointflag = 0;
    for(int i = 0; str[i] ; ++i)
    {
        if(pointflag)
        {
            point++;
        }
        if(str[i] == '.'){
            pointflag = 1;
        }else{
            ret = ret*10+str[i]-'0';
        }
    }
    while(point < 9) ret *= 10, point++;
    return ret;
}

int main()
{
#ifdef CitricAcid
    freopen ("input.txt", "rt", stdin);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        long long xint = inp();
        while(xint%2 == 0) cnt2[i]++, xint /= 2;
        while(xint%5 == 0) cnt5[i]++, xint /= 5;
        cnt[cnt2[i]][cnt5[i]]++;
    }
    for(int i = 64; i >= 0; --i)
        for(int j = 25; j >= 0; --j)
            cnt[i][j] = cnt[i][j] + cnt[i+1][j] + cnt[i][j+1] - cnt[i+1][j+1];
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int tmp2 = max(0, 18-cnt2[i]);
        int tmp5 = max(0, 18-cnt5[i]);
        ans += cnt[tmp2][tmp5];
        if(cnt2[i] >= tmp2 && cnt5[i] >= tmp5) ans--;
    }
    printf("%lld\n", ans/2);
}
