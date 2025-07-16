#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;


int main()
{
    int m;
    cin >> m;
    ll sum = 0, n = 0;
    rep(i,m)
    {
        ll c, d;
        cin >> d >> c;
        n += c;
        sum += c * d;
    }
    cout << n - 1 + ((sum - 1) / 9) << endl;
    
    return 0;
}