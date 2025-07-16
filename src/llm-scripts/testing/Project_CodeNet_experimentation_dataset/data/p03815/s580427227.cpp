#include <bits/stdc++.h>
using namespace std;

#define pb(s) push_back(s)
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L


typedef long long ll;

const ll MOD =1e9+7;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x;
    cin>>x;
    ll ans=0;
    ans+=2*(x/11);
    x%=11;
    if(x>0)ans++;
    if(x>6)ans++;
    cout<<ans;
    return 0;
}
