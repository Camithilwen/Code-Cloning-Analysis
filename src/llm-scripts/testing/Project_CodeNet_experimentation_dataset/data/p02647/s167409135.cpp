#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define point pair<int,int>

int N, K;
int mem[200010];

signed main()
{
    cin >> N >> K;
    rep(i, N)cin >> mem[i];
    rep(j, min(K, 100LL))
    {
        int tmp[400010] = {0};
        rep(i, N)
        {
            tmp[max(i - mem[i], 0LL)]++;
            tmp[i + mem[i] + 1]--;
        }
        rep(i, N)if(i)
            tmp[i] += tmp[i - 1];

        rep(i, N)mem[i] = tmp[i];
    }

    rep(i, N)
    {
        if(i)cout << " ";
        cout << mem[i];
    }cout << endl;

    return 0;
}
