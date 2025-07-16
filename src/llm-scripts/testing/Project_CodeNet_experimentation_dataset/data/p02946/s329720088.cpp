#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "E:\CP\Debugger\debugger.h"
#else 
#define debug(x...)
#endif
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int tc; cin>>tc; for(int cn=1; cn<=tc; ++cn) 
const int mx = 2e6+2, neg = -1e6, pos = 1e6;
bitset<mx> vis;

signed main(){
    int k, x;
    cin>>k>>x;

    int st = (x-k+1 >= neg? x-k+1: neg);
    int ed = (x+k-1 <= pos? x+k-1: pos);

    for(int i= st; i<=ed; ++i)
        cout<<i<<' ';

    return 0;
}