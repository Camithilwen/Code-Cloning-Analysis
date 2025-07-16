#include<bits/stdc++.h>

using namespace std;

#define TC ll t; cin >> t; while(t--)
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll k,x;
    cin >> k >> x;
    for(ll i=x-k+1;i<=x+k-1;i++)
    {
        cout << i << " ";
    }
    return 0;
}
