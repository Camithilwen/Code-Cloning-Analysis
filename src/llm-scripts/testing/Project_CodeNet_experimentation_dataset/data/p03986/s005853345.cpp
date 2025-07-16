#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

string S;

signed main()
{
    cin >> S;

    int tmp = 0;
    int ans = S.size();
    for(auto e : S)
    {
        if(e == 'T' && tmp)
        {
            tmp--;
            ans -= 2;
        }
        if(e == 'S')tmp++;
    }

    cout << ans << endl;

    return 0;
}
