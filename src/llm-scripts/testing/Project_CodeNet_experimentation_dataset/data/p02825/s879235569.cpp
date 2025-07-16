#include<bits/stdc++.h>
using namespace std;
void solve3()
{
    puts("aa.");
    puts("..b");
    puts("..b");
}
string mp[10][10];
void init()
{
    mp[4][0] = "aabc";
    mp[4][1] = "ddbc";
    mp[4][2] = "efgg";
    mp[4][3] = "efhh";
    mp[5][0] = "aabbc";
    mp[5][1] = "dee.c";
    mp[5][2] = "d.ffd";
    mp[5][3] = "eg..d";
    mp[5][4] = "eg.cc";
    mp[6][0] = "aab.cc";
    mp[6][1] = "ccbdd.";
    mp[6][2] = "d.aa.b";
    mp[6][3] = "d.c..b";
    mp[6][4] = ".ac..d";
    mp[6][5] = ".a.eed";
    mp[7][0] = "aab.c..";
    mp[7][1] = "..bdc..";
    mp[7][2] = "ee.d.ff";
    mp[7][3] = "c.bb..a";
    mp[7][4] = "c...eea";
    mp[7][5] = ".bcc..d";
    mp[7][6] = ".b..aad";
}
string ans[1001];
void fillit(int x, int m)
{
    for (int i = x, cnt = 0; cnt < m; i++, cnt++)
    {
        for (int j = 0; j < m; j++) ans[i][x + j] = mp[m][cnt][j];
    }
}
int main()
{
    init();
    int n; scanf("%d", &n);
    if (n == 2) puts("-1");
    else if (n == 3) solve3();
    else 
    {
        for (int i = 0; i < n; i++)
        {
            ans[i].resize(n); 
            fill(ans[i].begin(), ans[i].end(), '.');
        }
        int a = n / 4, b = n % 4;
        a--; b += 4;
        int now = 0;
        fillit(now, b); now += b;
        while (a--) fillit(now, 4), now += 4;
        for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    }
    return 0;
}