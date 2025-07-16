#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define rep(i,n) for(int i=0;i<n;i++)

int N;
int D[100010];
int mod = 998244353;

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int d;
        cin >> d;
        D[d]++;
        if(i == 0 && d != 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 1;
    rep(i, N)
    {
        if(i == 0 && D[i] != 1)
        {
            cout << 0 << endl;
            return 0;
        }
        int tmp = 1;
        if(i != 0)
            rep(j, D[i])tmp = tmp * D[i - 1] % mod;
        ans = ans * tmp % mod;
    }

    cout << ans << endl;
    
    return 0;
}