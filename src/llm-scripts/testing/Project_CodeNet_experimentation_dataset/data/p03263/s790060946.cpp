#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int H, W;
bool fid[510][510];
bool mem[510][510];
int cnt;

signed main()
{
    cin >> H >> W;

    rep(i, H)rep(j, W)
    {
        int a;
        cin >> a;
        fid[i][j] = a & 1;
        mem[i][j] = a & 1;
    }

    rep(i, H)rep(j, W - 1)
    {
        if(mem[i][j])
        {
            cnt++;
            mem[i][j + 1] ^= true;
        }
    }

    rep(i, H - 1)
    {
        if(mem[i][W - 1])
        {
            cnt++;
            mem[i + 1][W - 1] ^= true;
        }
    }

    cout << cnt << endl;

    rep(i, H)rep(j, W - 1)
    {
        if(fid[i][j])
        {
            cout << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 2 << endl;
            fid[i][j + 1] ^= true;
        }
    }

    rep(i, H - 1)
    {
        if(fid[i][W - 1])
        {
            cout << i + 1 << " " << W << " " << i + 2 << " " << W << endl;
            fid[i + 1][W - 1] ^= true;
        }
    }

    return 0;
}