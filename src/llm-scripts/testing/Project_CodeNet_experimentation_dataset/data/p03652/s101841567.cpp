#include <bits/stdc++.h>

///    ____ ____ ____ ____ ____
///   ||a |||t |||o |||d |||o ||
///   ||__|||__|||__|||__|||__||
///   |/__\|/__\|/__\|/__\|/__\|
///

using namespace std;

const int N_MAX = 302;
const int M_MAX = 302;

int n, m;

int a[N_MAX][M_MAX];

bool del[N_MAX];

int pos[N_MAX];

int cnt[M_MAX];

queue <int> q;

bool f (int mx)
{
    for(int i = 1; i <= m; i++)
    {
        del[i] = false;
        cnt[i] = 0;
    }
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= n; i++)
    {
        pos[i] = 1;
        if(++cnt[a[i][1]] == mx + 1)
            q.push(a[i][1]);
    }
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        del[f] = true;
        for(int i = 1; i <= n; i++)
            if(del[a[i][pos[i]]] == true)
            {
                while(pos[i] <= m && del[a[i][pos[i]]] == true)
                    pos[i]++;
                if(pos[i] == m + 1)
                    return false;
                if(++cnt[a[i][pos[i]]] == mx + 1)
                    q.push(a[i][pos[i]]);
            }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    int l = 1, r = n;
    while(l < r)
    {
        int mid = ((l + r) >> 1);
        if(f(mid) == true)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}
